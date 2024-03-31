import tkinter as tk
from tkinter import ttk, scrolledtext
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Input data
x = np.array([3, 4, 5, 6, 7])

def calculate_polynomial_coeffs(x, y, degree):
    # Calculate polynomial coefficients for given degree using least squares method
    if degree == 1:
        # Linear polynomial (a*x + b)
        n = len(x)
        sum_x, sum_y, sum_xy, sum_x2 = sum(x), sum(y), sum(x*y), sum(x**2)
        a = (n*sum_xy - sum_x*sum_y) / (n*sum_x2 - sum_x**2)
        b = (sum_y - a*sum_x) / n
        return a, b
    elif degree == 2:
        # Quadratic polynomial (a*x^2 + b*x + c)
        n = len(x)
        sum_x, sum_x2, sum_x3, sum_x4 = sum(x), sum(x**2), sum(x**3), sum(x**4)
        sum_y, sum_xy, sum_x2y = sum(y), sum(x*y), sum(x**2*y)
        A = np.array([[sum_x4, sum_x3, sum_x2],
                      [sum_x3, sum_x2, sum_x],
                      [sum_x2, sum_x, n]])
        B = np.array([sum_x2y, sum_xy, sum_y])
        a, b, c = np.linalg.solve(A, B)
        return a, b, c

def lagrange_interpolation(x, y, xi):
    # Perform Lagrange interpolation for a given set of x and y values and a point xi
    sum = 0
    n = len(x)
    for i in range(n):
        product = y[i]
        for j in range(n):
            if i != j:
                product *= (xi - x[j])/(x[i] - x[j])
        sum += product
    return sum

def calculate_sse(y_true, y_pred):
    # Calculate the sum of squared errors (SSE) between true and predicted y values
    sse = sum((y_true - y_pred) ** 2)
    return sse

def plot_approximation_and_interpolation(n, text_widget, tree):
    # Plot the results of polynomial approximation and Lagrange interpolation based on input value n
    # Update the GUI text widget with coefficients, SSE, and best fit determination
    update_table(n, tree)
    y = np.array([2.5*n, 3.6, -0.8, -1.9, -1.1])
    linear_coeffs = calculate_polynomial_coeffs(x, y, 1)
    quadratic_coeffs = calculate_polynomial_coeffs(x, y, 2)
    
    # Generate points for plotting polynomial curves
    x_vals = np.linspace(x[0], x[-1], 100)
    y_linear = linear_coeffs[0] * x_vals + linear_coeffs[1]
    y_quadratic = quadratic_coeffs[0] * x_vals**2 + quadratic_coeffs[1] * x_vals + quadratic_coeffs[2]
    y_lagrange = [lagrange_interpolation(x, y, xi) for xi in x_vals]

    # Calculate SSE for both polynomial fits
    linear_sse = calculate_sse(y, linear_coeffs[0] * x + linear_coeffs[1])
    quadratic_sse = calculate_sse(y, quadratic_coeffs[0] * x**2 + quadratic_coeffs[1] * x + quadratic_coeffs[2])
    
    # Update the GUI text widget with results
    text_widget.delete('1.0', tk.END)
    text_widget.insert(tk.END, f"Linear Coeffs:\na = {linear_coeffs[0]:.2f},\nb = {linear_coeffs[1]:.2f},\nSSE: {linear_sse:.2f}\n")
    text_widget.insert(tk.END, f"Quadratic Coeffs:\na = {quadratic_coeffs[0]:.2f},\nb = {quadratic_coeffs[1]:.2f},\nc = {quadratic_coeffs[2]:.2f},\nSSE: {quadratic_sse:.2f}\n")
    
    best_fit = "linear" if linear_sse < quadratic_sse else "quadratic"
    text_widget.insert(tk.END, f"The {best_fit} polynomial provides the best fit based on SSE\n")

    df = pd.DataFrame({
        'x': x_vals,
        'y (Lagrange Interpolation)': y_lagrange
    })
    print(df)
    
    # Plot the approximations and interpolation
    plt.figure(num="Approximation and Interpolation Plot", figsize=(8, 6))
    plt.plot(x_vals, y_linear, 'r-', label='Linear Approximation')
    plt.plot(x_vals, y_quadratic, 'b-', label='Quadratic Approximation')
    plt.plot(x_vals, y_lagrange, 'g-', label='Lagrange Interpolation')
    plt.plot(x, y, 'ko', label='Original Data')
    plt.legend()
    plt.grid(True)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Approximation and Interpolation')
    plt.show(block=False)

def update_table(n, tree):
    # Update the table with x and y values based on the input n
    for i in tree.get_children():
        tree.delete(i)
    
    y_values = np.array([2.5*n, 3.6, -0.8, -1.9, -1.1])

    for i in range(len(x)):
        tree.insert('', 'end', values=(x[i], y_values[i]))

# GUI setup
root = tk.Tk()
root.title("Approximation and Interpolation")

frame = ttk.Frame(root)
frame.pack(padx=10, pady=10)

n_label = ttk.Label(frame, text="Enter n value:")
n_label.pack()

n_entry = ttk.Entry(frame)
n_entry.pack()

tree = ttk.Treeview(frame, columns=('X', 'Y'), show='headings', height=5)
tree.column('X', width=100)
tree.column('Y', width=100)
tree.heading('X', text='X')
tree.heading('Y', text='Y')
tree.pack()

results_text = scrolledtext.ScrolledText(frame, height=15, width=50)
results_text.pack()

calculate_button = ttk.Button(frame, text="Calculate", command=lambda: plot_approximation_and_interpolation(float(n_entry.get()), results_text, tree))
calculate_button.pack()

root.mainloop()
