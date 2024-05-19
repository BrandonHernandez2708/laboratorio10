import tkinter as tk
import serial


ser = serial.Serial('COM3', 9600)  

def send_command(direccion):
    try:
        angulo = int(angulo_entry.get())
        
        if direccion == 'Girar a la derecha':
            ser.write(b'd')
        else:
            ser.write(b'i')
            
        ser.write(f"{angulo}\n".encode())
    except ValueError:
        print("Ingrese un valor valido.")

#dashboard
root = tk.Tk()
root.title("Servo Control")

tk.Label(root, text="Ángulo (0-180):").pack(pady=5)
angulo_entry = tk.Entry(root)
angulo_entry.pack(pady=5)

tk.Label(root, text="Velocidad").pack(pady=5)
speed_entry = tk.Entry(root)
speed_entry.pack(pady=5)

tk.Button(root, text="Rotar a la Derecha", command=lambda: send_command('right')).pack(pady=5)
tk.Button(root, text="Rotar a la Izquierda", command=lambda: send_command('left')).pack(pady=5)

root.mainloop()
