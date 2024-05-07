from prettytable import PrettyTable
import matplotlib.pyplot as plt

# Step size, initial conditions, x-value endpoint for the methods
h = 0.05
x0 = 0
y0 = 2
x_end = 4

# Function for the differential equation
def fun(x, y):
    return (1 - y**2) * x + 0.6 * y

# Print initial settings
print("Initial Settings:")
print(f"Differential Equation: \033[33my' = (1 - y^2)x + 0.6y\033[0m")
print(f"Initial Condition: \033[35my({x0}) = {y0}\033[0m")
print(f"Step size (h): \033[34m{h}\033[0m")
print(f"Calculation range: \033[32mx from {x0} to {x_end}\n\033[0m")

# Euler method
def euler_method(x0, y0, x_end, h):
    x = x0
    y = y0
    values = []
    while x <= x_end:
        values.append((x, y, fun(x, y), h * fun(x, y))) # Append current state to the values list
        y += h * fun(x, y)  # Update y based on the Euler method formula
        x += h  # Increment x by step size h
    return values

# Runge-Kutta method
def runge_kutta_method(x0, y0, x_end, h):
    x = x0
    y = y0
    values = []
    while x <= x_end:
        # Calculate k1, k2, k3, k4 for Runge-Kutta formula
        k1 = fun(x, y)
        k2 = fun(x + h / 2, y + h / 2 * k1)
        k3 = fun(x + h / 2, y + h / 2 * k2)
        k4 = fun(x + h, y + h * k3)
        values.append((x, y, fun(x, y), k1, x + h/2, y + h/2 * k1, k2, y + h/2 * k2, k3, x + h, y + h * k3, k4))    # Append all intermediate and final states to the values list
        y += h / 6 * (k1 + 2 * k2 + 2 * k3 + k4)    # Update y based on the Runge-Kutta method formula
        x += h  # Increment x by step size h
    return values

# Execute the Euler and Runge-Kutta methods
euler_values = euler_method(x0, y0, x_end, h)
runge_kutta_values = runge_kutta_method(x0, y0, x_end, h)

# Create tables for displaying the results of each method
euler_table = PrettyTable()
euler_table.field_names = ["\033[36mx", "y", "f(x, y)", "hf(x, y)\033[0m"]
for val in euler_values:
    euler_table.add_row([f"{val[0]:.4f}", f"{val[1]:.4f}", f"{val[2]:.4f}", f"{val[3]:.4f}"])

runge_kutta_table = PrettyTable()
runge_kutta_table.field_names = ["\033[36mx", "y", "f(x, y)", "k1", "x+h/2", "y+h/2*k1", "k2", "y+h/2*k2", "k3", "x+h", "y+h*k3", "k4\033[0m"]
for val in runge_kutta_values:
    runge_kutta_table.add_row([f"{val[0]:.4f}", f"{val[1]:.4f}", f"{val[2]:.4f}", f"{val[3]:.4f}", f"{val[4]:.4f}", f"{val[5]:.4f}", f"{val[6]:.4f}", f"{val[7]:.4f}", f"{val[8]:.4f}", f"{val[9]:.4f}", f"{val[10]:.4f}", f"{val[11]:.4f}"])

# Print the tables
print("Euler Method Values:")
print(euler_table)

print("\nRunge-Kutta Method Values:")
print(runge_kutta_table)

# Create plots for Euler and Runge-Kutta methods results
plt.figure(num='Solutions of Differential Equations', figsize=(12, 10))

plt.subplot(2, 1, 1)
plt.plot([val[0] for val in euler_values], [val[1] for val in euler_values], 'b.-', label='Euler Method Solution')
plt.title('Euler Method')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.legend()

plt.subplot(2, 1, 2)
plt.plot([val[0] for val in runge_kutta_values], [val[1] for val in runge_kutta_values], 'r.-', label='Runge-Kutta Method Solution')
plt.title('Runge-Kutta Method')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()
