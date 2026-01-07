from abc import ABC, abstractmethod
from datetime import date

class Transacao(ABC):

    @abstractmethod
    def registrar(self, conta):
        pass

class Deposito(Transacao):
    def __init__(self, valor: float):
        self.valor = valor

    def registrar(self, conta):
        conta.depositar(self.valor)
        conta.historico.adicionar_transacao(self)

class Saque(Transacao):
    def __init__(self, valor: float):
        self.valor = valor

    def registrar(self, conta):
        if conta.sacar(self.valor):
            conta.historico.adicionar_transacao(self)

class Historico:
    def __init__(self):
        self.transacoes = []

    def adicionar_transacao(self, transacao: Transacao):
        self.transacoes.append(transacao)

    def gerar_extrato(self):
        extrato = ""
        for t in self.transacoes:
            nome = t.__class__.__name__
            extrato += f"{nome}: R$ {t.valor:.2f}\n"
        return extrato

class Conta:
    def __init__(self, cliente, numero, agencia="0001"):
        self._saldo = 0.0
        self.numero = numero
        self.agencia = agencia
        self.cliente = cliente
        self.historico = Historico()

    def saldo(self):
        return self._saldo

    def sacar(self, valor: float) -> bool:
        if valor <= 0 or valor > self._saldo:
            print("Operação falhou! Saque inválido.")
            return False

        self._saldo -= valor
        return True

    def depositar(self, valor: float) -> bool:
        if valor <= 0:
            print("Operação falhou! Depósito inválido.")
            return False

        self._saldo += valor
        return True

class ContaCorrente(Conta):
    def __init__(self, cliente, numero, limite=500, limite_saques=3):
        super().__init__(cliente, numero)
        self.limite = limite
        self.limite_saques = limite_saques

    def sacar(self, valor: float) -> bool:
        saques_realizados = len(
            [t for t in self.historico.transacoes if isinstance(t, Saque)]
        )

        if saques_realizados >= self.limite_saques:
            print("Limite de saques excedido.")
            return False

        if valor > self.limite:
            print("Valor excede o limite.")
            return False

        return super().sacar(valor)

class Cliente:
    def __init__(self, endereco):
        self.endereco = endereco
        self.contas = []

    def adicionar_conta(self, conta: Conta):
        self.contas.append(conta)

    def realizar_transacao(self, conta: Conta, transacao: Transacao):
        transacao.registrar(conta)

class PessoaFisica(Cliente):
    def __init__(self, nome, cpf, data_nascimento, endereco):
        super().__init__(endereco)
        self.nome = nome
        self.cpf = cpf
        self.data_nascimento = data_nascimento

def filtrar_cliente(cpf, clientes):
    for cliente in clientes:
        if cliente.cpf == cpf:
            return cliente
    return None


def menu():
    return """
[d] Depositar
[s] Sacar
[e] Extrato
[u] Cadastrar Usuário
[c] Cadastrar Conta
[q] Sair
=> """

clientes = []
contas = []

while True:
    opcao = input(menu())

    if opcao == "u":
        nome = input("Nome: ")
        cpf = "".join(filter(str.isdigit, input("CPF: ")))
        nascimento = input("Data nascimento (AAAA-MM-DD): ")
        endereco = input("Endereço: ")

        if filtrar_cliente(cpf, clientes):
            print("Cliente já cadastrado.")
            continue

        cliente = PessoaFisica(nome, cpf, nascimento, endereco)
        clientes.append(cliente)
        print("Cliente cadastrado.")

    elif opcao == "c":
        cpf = "".join(filter(str.isdigit, input("CPF: ")))
        cliente = filtrar_cliente(cpf, clientes)

        if not cliente:
            print("Cliente não encontrado.")
            continue

        numero = len(contas) + 1
        conta = ContaCorrente(cliente, numero)
        cliente.adicionar_conta(conta)
        contas.append(conta)
        print("Conta criada.")

    elif opcao == "d":
        cpf = "".join(filter(str.isdigit, input("CPF: ")))
        cliente = filtrar_cliente(cpf, clientes)

        if not cliente or not cliente.contas:
            print("Conta não encontrada.")
            continue

        valor = float(input("Valor do depósito: "))
        transacao = Deposito(valor)
        cliente.realizar_transacao(cliente.contas[0], transacao)

    elif opcao == "s":
        cpf = "".join(filter(str.isdigit, input("CPF: ")))
        cliente = filtrar_cliente(cpf, clientes)

        if not cliente or not cliente.contas:
            print("Conta não encontrada.")
            continue

        valor = float(input("Valor do saque: "))
        transacao = Saque(valor)
        cliente.realizar_transacao(cliente.contas[0], transacao)

    elif opcao == "e":
        cpf = "".join(filter(str.isdigit, input("CPF: ")))
        cliente = filtrar_cliente(cpf, clientes)

        if not cliente or not cliente.contas:
            print("Conta não encontrada.")
            continue

        conta = cliente.contas[0]
        print("\n========== EXTRATO ==========")
        print(conta.historico.gerar_extrato() or "Sem movimentações.")
        print(f"Saldo: R$ {conta.saldo():.2f}")
        print("=============================")

    elif opcao == "q":
        break

    else:
        print("Opção inválida.")
