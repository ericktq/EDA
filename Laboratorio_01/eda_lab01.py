# -*- coding: utf-8 -*-
"""EDA_LAB01.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1sIN6zIZ1zFWmdW_2B4gVXYXcCDyvBsu9
"""

from google.colab import files
uploaded = files.upload()

import matplotlib.pyplot as plt
import numpy as np
import os

dimensiones = [10, 50, 100, 500, 1000, 2000, 5000]

def leer_distancias(dimension):
    archivo = f"distancias_dim{dimension}.txt"
    if os.path.exists(archivo):
        with open(archivo, "r") as f:
            distancias = [float(line.split(":")[1]) for line in f.readlines()]
        return distancias
    else:
        print(f"El archivo {archivo} no existe.")
        return []

for dim in dimensiones:
    distancias = leer_distancias(dim)
    if distancias:
        plt.figure(figsize=(8, 6))
        plt.hist(distancias, bins=50, color='skyblue', edgecolor='black')
        plt.title(f"Histograma de Distancias (Dimensión {dim})")
        plt.xlabel("Distancia")
        plt.ylabel("Frecuencia")
        plt.show()