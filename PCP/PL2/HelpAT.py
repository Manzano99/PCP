import ctypes
import numpy as np 

from numpy.ctypeslib import ndpointer as ND
from numpy           import linalg    as LA
from random          import random     

LibAT = ctypes.cdll.LoadLibrary('LIBS/HelpAT.so')
CTran = LibAT.MyTrans

CTran.restype  = None
CTran.argtypes = [ctypes.c_int, ctypes.c_int, ND(ctypes.c_double, flags="F"), ND(ctypes.c_double, flags="F")]

talla = [200]
rept  = [  1]

for i in range(0,len(talla)):
   m = talla[i]
   n = m-1
   
   A   = np.random.rand(m, n).astype(np.float64)
   CAT = np.zeros((n, m), dtype=np.float64)

   # Python 
   PythonAT = np.transpose(A)

   # C
   A   = np.asarray(A,   order='F')
   CAT = np.asarray(CAT, order='F')
   CTran(m, n, A, CAT)

   # El error
   print(f"El error entre la transpuesta de Python y C es:{LA.norm(PythonAT-CAT, 'fro'):1.5E}")

