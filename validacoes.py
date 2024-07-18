import re
from datetime import datetime

### FUNÇÕES ###


def ano_bissexto(ano):
    return (ano % 4 == 0) and (ano % 100 != 0) or (ano % 400 == 0)

def validar_data(data):
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

    if ano_bissexto(data_ano) and data_mes == 2:
        if data_dia > 29:
            return False
    elif not ano_bissexto(data_ano) and data_mes == 2:
        if data_dia > 28:
            return False

    return True

# ChatGPT
def validar_cpf(cpf):
    # Remove caracteres não numéricos do CPF
    cpf = ''.join(filter(str.isdigit, cpf))

    # Verifica se o CPF tem 11 dígitos e se não é uma sequência repetida
    if len(cpf) != 11 or cpf == cpf[0] * 11:
        return False

    # Calcula o primeiro dígito verificador
    soma = 0
    for i in range(9):
        soma += int(cpf[i]) * (10 - i)
    digito1 = 11 - (soma % 11)
    if digito1 > 9:
        digito1 = 0

    # Verifica o primeiro dígito verificador
    if int(cpf[9]) != digito1:
        return False

    # Calcula o segundo dígito verificador
    soma = 0
    for i in range(10):
        soma += int(cpf[i]) * (11 - i)
    digito2 = 11 - (soma % 11)
    if digito2 > 9:
        digito2 = 0

    # Verifica o segundo dígito verificador
    if int(cpf[10]) != digito2:
        return False

    # Se passar por todas as verificações, o CPF é válido
    return True

def validar_email(email):
    regex_email = r"([a-zA-Z0-9\.\-\_]{2,})@([a-zA-Z0-9]{2,})(\.[a-zA-Z]{2,})(\.[a-zA-Z]{2,})?(\.[a-z]{2,})?"
    if not re.match(regex_email, email):
        return False
    return True

def validar_nome_regex(nome):
    regex_nome = r"^[A-Za-zÀ-ÿ]+( [A-Za-zÀ-ÿ]+)*$"
    if not re.match(regex_nome, nome):
        return False
    if not all(palavra[0].isupper() for palavra in nome.split()):
        return False
    return True

def validarNome(nome):
    nome_sem_espacos = nome.replace(' ', '')
    if not nome_sem_espacos.isalpha():
        return False
    return True

def validar_quantidade(qtd):
    qtd = qtd.replace(' ', '')
    if not(qtd.isdigit()):
        return False
    return True

def validar_preco(preco):
    regex_preco = r"([0-9]{1,}(?:\.[0-9]{3})*)[,\.]([0-9]{2})"
    preco = preco.replace(',', '.')
    if not re.match(regex_preco, preco):
        return False
    return True

def validar_telefone(tel):
    tel = ''.join(filter(str.isdigit, tel))

    tam = len(tel)
    if tam < 11 or tam > 11:
        return False
    if not tel.isdigit():
        return False

    return True


def validar_forma_pag(dicio, op):
    if op not in dicio:
        return False
    return True

####################
###### TESTES ######

# if validarNome('diana rodrieus'):
#     print("eeeeeee")
# else:
#     print('aaaaaaa')


def checar_repetidos(telefone):
    # Checa se todos os caracteres da string são iguais
    return telefone.count(telefone[0]) == len(telefone)

# Exemplo de uso
tel = '88884888888'
resultado = checar_repetidos(tel)
print(f"A string '{tel}' só tem caracteres repetidos? {resultado}")
