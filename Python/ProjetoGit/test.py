import tkinter as tk
from tkinter import filedialog

def selecionar_arquivo():
    caminho = filedialog.askopenfilename(
        title="Selecione um arquivo",
        filetypes=(("Arquivos de texto", "*.txt"), ("Todos os arquivos", "*.*"))
    )
    if caminho:
        print("Arquivo selecionado:", caminho)

# Criar janela
root = tk.Tk()
root.title("Exemplo Selecionar Arquivo")

botao = tk.Button(root, text="Selecionar Arquivo", command=selecionar_arquivo)
botao.pack(pady=20)

root.mainloop()
