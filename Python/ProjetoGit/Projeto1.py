"""
1 - Concatenação de dados
- Manipular string
- Concatenar dados
- Entrada de dados
- Utilização eficiente do github copilot

2 - Repetindo textos
- Manipulação de strings
- Números inteiros
- Multiplas repetições
- Entadas de dados
- Aproveitar as sugestões do github copilot

3 - Operações matemáticas simples
- Operações matemáticas básicas
- Entrada de dados
- Utilização eficiente do github copilot
"""

# Vamos receber dois dados diferentes do usuário e concatena-los em uma única string
info1 = input("Digite o primeiro texto: ")
info2 = input("Digite o texto a ser multiplicado: ")
rep = int(input("Digite quantas vezes multiplicar:"))

info_concatenada = info1 + " " + rep*info2

print("As informações concatenadas são: ", info_concatenada)