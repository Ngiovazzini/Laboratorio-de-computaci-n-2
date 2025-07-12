import csv

#Mapa echo en Tiled en este CSV esta la matriz
def cargar_mapa(ruta):
    mapa = []
    with open(ruta, newline='') as archivo:
        lector = csv.reader(archivo, delimiter=',')
        for fila in lector:
            mapa.append([int(celda) for celda in fila])
    return mapa
matriz_mapa = cargar_mapa('sprits/Mapa.csv')