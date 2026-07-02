import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("output/trajectory.csv")

plt.figure(figsize=(12, 5))

plt.subplot(1, 2, 1)
plt.plot(df["x"], df["y"], linewidth=2, color="royalblue")
plt.xlabel("Distância (m)")
plt.ylabel("Altura (m)")
plt.title("Trajetória do Projétil com Arrasto")
plt.grid(True, alpha=0.3)

plt.subplot(1, 2, 2)
plt.plot(df["time"], df["x"], label="x (horizontal)", linewidth=2)
plt.plot(df["time"], df["y"], label="y (vertical)", linewidth=2)
plt.xlabel("Tempo (s)")
plt.ylabel("Posição (m)")
plt.title("Posição vs Tempo")
plt.legend()
plt.grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig("docs/trajectory.png", dpi=150)
plt.show()
