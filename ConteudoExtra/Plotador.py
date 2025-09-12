import matplotlib.pyplot as plt

# Lê o número de pontos
n = int(input("Digite o número de pontos: "))

xs = []
ys = []

print(f"Agora digite {n} pontos (x y), um por linha:")

# Lê os pontos na sequência
for _ in range(n):
    x, y = map(float, input().split())
    xs.append(x)
    ys.append(y)

# Plota os pontos
plt.figure(figsize=(6,6))
plt.scatter(xs, ys, color="blue", s=80, label="Pontos")
plt.plot(xs, ys, linestyle="--", color="gray", alpha=0.5)

# Configurações
plt.xlim(-10, 10)
plt.ylim(-10, 10)
plt.axhline(0, color="black", linewidth=1)
plt.axvline(0, color="black", linewidth=1)
plt.grid(True, linestyle="--", alpha=0.5)
plt.legend()
plt.title("Visualização de Pontos")

plt.show()