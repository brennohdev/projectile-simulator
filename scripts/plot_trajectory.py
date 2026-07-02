import pandas as pd
import matplotlib.pyplot as plt

df_drag = pd.read_csv("output/with_drag.csv")
df_no = pd.read_csv("output/no_drag.csv")

plt.figure(figsize=(10, 5))
plt.plot(df_no["x"], df_no["y"], "--", label="No drag (vacuum)", linewidth=2)
plt.plot(df_drag["x"], df_drag["y"], label="With drag (air)", linewidth=2)
plt.xlabel("Distance (m)")
plt.ylabel("Height (m)")
plt.title("Effect of Aerodynamic Drag on Trajectory")
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig("docs/comparison.png", dpi=150)
plt.show()
