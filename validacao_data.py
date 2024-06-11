import re
from datetime import datetime


def anoBisexto(ano):
    return (ano % 4 == 0) and (ano % 100 != 0) or (ano % 400 == 0)


ano_atual = datetime.now().year
regex_data = r"([0-9]{2})/([0-9]{2})/([0-9]{4})"

data = input("digite uma data: ").strip()
data_dia = int(data.split("/")[0])
data_mes = int(data.split("/")[1])
data_ano = int(data.split("/")[2])

while not re.match(regex_data, data):
    print("Data com formato invalido")
    data = input("digite uma data: ")

print(data_dia, data_mes, data_ano)

if data_ano < 1900 or data_ano > ano_atual:
    print("Data invalida. Não é possível que tenha nascido esse ano. ")

if data_mes < 1 or data_mes > 12:
    print("Data invalida. Esse mes não existe.")

if data_dia < 1:
    print("Data inválida. Não existe dia 0.")

if data_mes in [4, 6, 9, 11] and data_dia > 30:
    print("Data invalida, esse mes tem 30 dias.")

if anoBisexto(data_ano) and data_mes == 2:
    if data_dia > 29:
        print("Data inválida. Fevereiro tem no máximo 29 dias esse ano.")
elif not anoBisexto(data_ano) and data_mes == 2:
    if data_dia > 28:
        print("Data inválida. Fevereiro tem no máximo 28 dias esse ano.")
