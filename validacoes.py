import re
from datetime import datetime

### FUNÇÕES ###

def anoBissexto(ano):
    return (ano % 4 == 0) and (ano % 100 != 0) or (ano % 400 == 0)

def validarData(data):
    ano_atual = datetime.now().year
    regex_data = r"([0-9]{2})/([0-9]{2})/([0-9]{4})"

    data_dia, data_mes, data_ano = map(int, data.split("/"))
    
    if not re.match(regex_data, data):
        return False

    print(data_dia, data_mes, data_ano)

    if data_ano < 1900 or data_ano > ano_atual:
        return False

    if data_mes < 1 or data_mes > 12:
        return False

    if data_dia < 1 or data_dia > 31:
        return False

    if data_mes in [4, 6, 9, 11] and data_dia > 30:
        return False

    if anoBissexto(data_ano) and data_mes == 2:
        if data_dia > 29:
            return False
    elif not anoBissexto(data_ano) and data_mes == 2:
        if data_dia > 28:
            return False

    return True

def validarEmail(email):
    regex_email = r"([a-z0-9\.\-\_]{2,})@([a-z0-9]{2,})(\.[a-z]{2,})(\.[a-z]{2,})?(\.[a-z]{2,})?"
    
    if not re.match(regex_email, email):
        return False
    
    return True

def validarNome(nome):
    regex_nome = r"^[A-Za-zÀ-ÿ]+( [A-Za-zÀ-ÿ]+)*$"
    
    if not re.match(regex_nome, nome):
        return False
    
    if not all(palavra[0].isupper() for palavra in nome.split()):
        return False
    return True

def validarTelefone(tel):
    # colocar o ddd ou não? 
    regex_tel = r"(\([0-9]{2}\) )([0-9]{4,5}-)([0-9]{4})"
    
    if not re.match(regex_tel, tel):
        print("padrão errado")
        return False
    
    return True

def validarFormaPagamento(dicio, op):
    if op not in dicio:
        return False
    return True

### PROGRAMA PRINCIPAL ###

# data = input("Digite uma data: ").strip()

# while validarData(data) != True:
#     print("Data invalida. Cheque a data e digite novamente.\n")
#     data = input("Digite a data novamente: ")

# email = input("Digite um email: ").lstrip().rstrip()

# while validarEmail(email) != True:
#     print("Email inválido. Cheque o email e digite novamente: ")
#     email = input("Digite o email novamente: ")

# nome = input("Digite um nome: ")

# while validarNome(nome) != True:
#     print("Nome inválido. Cheque o nome e digite novamente: ")
#     nome = input("Digite o nome novamente: ")

# telefone = input("Digite um telefone: ")

# while validarTelefone(telefone) != True:
#     print("Telefone inválido. Cheque o telefone e digite novamente: ")
#     telefone = input("Digite o telefone novamente: ")

dicio_teste = {1: "Cartão de Credito", 2: "Cartão de Débito", 3: "Especie", 4: "Pix"}
opcao = int(input("Digite uma opção entre 1 e 4: "))

while validarFormaPagamento(dicio_teste, opcao) != True:
    print("Opção invalida.")
    opcao = int(input("Digite uma opção entre 1 e 4: "))

if opcao in dicio_teste:
    print(dicio_teste[opcao])