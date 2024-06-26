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

def validarNomeRegex(nome):
    regex_nome = r"^[A-Za-zÀ-ÿ]+( [A-Za-zÀ-ÿ]+)*$"
    if not re.match(regex_nome, nome):
        return False
    if not all(palavra[0].isupper() for palavra in nome.split()):
        return False
    return True

def validarNome(nome):
    nome = nome.strip()
    nome = re.sub(r'\s+', ' ', nome)
    if not all(palavra[0].isupper() for palavra in nome.split()):
        return False
    nome_sem_espacos = nome.replace(' ', '')
    if not nome_sem_espacos.isalpha():
        return False
    return nome

def validarQuantidade(qtd):
    qtd = qtd.replace(' ', '')
    if not(qtd.isdigit()):
        return False
    return True

def validarPreco(preco):
    regex_preco = r"([0-9]{1,}(?:\.[0-9]{3})*)[,\.]([0-9]{2})"
    preco = preco.replace(',', '.')
    if not re.match(regex_preco, preco):
        return False
    return True

def validarTelefone(tel):
    # colocar o ddd ou não?
    regex_tel = r"(\([0-9]{2}\) )([0-9]{4,5}-)([0-9]{4})"
    if not re.match(regex_tel, tel):
        return False
    return True


def validarFormaPagamento(dicio, op):
    if op not in dicio:
        return False
    return True
