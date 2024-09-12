
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
