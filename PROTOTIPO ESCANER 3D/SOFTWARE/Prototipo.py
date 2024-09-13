
#  Software Prototipo de Escáner 3D
#  Autor: José Ruiz

#Librerías
import os
import subprocess
import imghdr
from tkinter import filedialog
import open3d as o3d
import threading
from PIL import Image
import customtkinter

# Ruta completa del ejecutable de COLMAP
COLMAP_PATH = "C:/Users/José Ruiz/Documents/ESPE/TRABAJO UIC 202450/DESARROLLO DEL PROTOTIPO DE ESCANER 3D/5. SOFTWARE DEL PROTOTIPO/SOFTWARE PROTOTIPO DE ESCANER 3D/Protipo_escaner_3D/colmap-x64-windows-nocuda/bin/colmap.exe"

# Directorios de trabajo
BASE_DIR = os.getcwd()
IMAGE_DIR = os.path.join(BASE_DIR, 'images')
DATABASE_PATH = os.path.join(BASE_DIR, 'database.db')
SPARSE_DIR = os.path.join(BASE_DIR, 'sparse')
DENSE_DIR = os.path.join(BASE_DIR, 'dense')
MODEL_DIR = os.path.join(BASE_DIR, 'model.ply')
MESH_DIR = os.path.join(BASE_DIR, 'mesh.ply')

# Función para asegurar que los directorios existen
def ensure_directory_exists(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)

# Asegurarse de que los directorios de salida existen
ensure_directory_exists(SPARSE_DIR)
ensure_directory_exists(DENSE_DIR)