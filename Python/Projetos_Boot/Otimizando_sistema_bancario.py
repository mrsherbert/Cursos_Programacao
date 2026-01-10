saldo = 0
limite = 500
extrato = ""
numero_saques = 0
LIMITE_SAQUES = 3
usuarios = []
contas = []

def cadastrar_usuario(usuarios):
    nome = input("Informe o nome:")
    nascimento = input("Informe a data de nascimento:")
    cpf = input("Informe o CPF:")
    endereco = input("Informe o endereço:")

    cpf = "".join(filter(str.isdigit, cpf))

    for user in usuarios:
        if user["cpf"] == cpf:
            print("Usuário já existe.")
            return

    usuario = {
        "nome": nome,
        "data_nascimento": nascimento,
        "cpf": cpf,
        "endereco": endereco
    }

    usuarios.append(usuario)
    print("Usuário cadastrado")

def cadastrar_conta(contas):
    agencia = input("Informe a agência:")
    cpf = input("Informe o CPF:")

    cpf = "".join(filter(str.isdigit, cpf))

    valor_atual = 0
    for conta in contas:
        if conta["agencia"] == agencia:
            if conta["numero_conta"] > valor_contas:
                valor_atual = conta["numero_conta"]
    
    conta = {
        "agencia": agencia,
        "numero_conta": valor_atual + 1,
        "cpf": cpf
    }
    
    contas.append(conta)
    print("Conta cadastrada")

def depositar(saldo, extrato, /):
    valor = float(input("Informe o valor do depósito: "))

    if valor > 0:
        saldo += valor
        extrato += f"Depósito: R$ {valor:.2f}\n"
    else:
        print("Operação falhou! O valor informado é inválido.")
    
    return saldo, extrato

def sacar(LIMITE_SAQUES, *, saldo_s, extrato_s, num_saques_s, lim_s):
    valor = float(input("Informe o valor do saque: "))

    excedeu_saldo = valor > saldo_s
    excedeu_limite = valor > lim_s
    excedeu_saques = num_saques_s >= LIMITE_SAQUES

    if excedeu_saldo:
        print("Operação falhou! Você não tem saldo suficiente.")
    elif excedeu_limite:
        print("Operação falhou! O valor do saque excede o limite.")
    elif excedeu_saques:
        print("Operação falhou! Número máximo de saques excedido.")
    elif valor > 0:
        saldo_s -= valor
        extrato_s += f"Saque: R$ {valor:.2f}\n"
        num_saques_s += 1
    else:
        print("Operação falhou! O valor informado é inválido.")

    return saldo_s, extrato_s, num_saques_s

def exibir_extrato(saldo, /, *, extrato_s):
    print("\n================ EXTRATO ================")
    print("Não foram realizadas movimentações." if not extrato_s else extrato_s)
    print(f"\nSaldo: R$ {saldo:.2f}")
    print("==========================================")

menu = """

[d] Depositar
[s] Sacar
[e] Extrato
[q] Sair
[u] Cadastrar Usuário 
[c] Cadastrar Conta

=> """

while True:
    opcao = input(menu)

    if opcao == "d":
        saldo, extrato = depositar(saldo, extrato)

    elif opcao == "s":
        saldo, extrato, numero_saques = sacar(
            LIMITE_SAQUES,
            saldo_s=saldo,
            extrato_s=extrato,
            num_saques_s=numero_saques,
            lim_s=limite
        )

    elif opcao == "e":
        exibir_extrato(saldo, extrato_s=extrato)

    elif opcao == "q":
        break

    elif opcao == "u":
        cadastrar_usuario(usuarios)
    
    elif opcao == "c":
        cadastrar_conta(contas)

    else:
        print("Operação inválida.")
