import numpy as np
import pandas as pd
import seaborn as sns
import math
import matplotlib.pyplot as plt
sns.set()

df = pd.read_csv("todos10k.csv")

ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['Algo'] == "FB"]);
ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['Algo'] == "MitM"]);
#ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['Algo'] == "BT"]);
ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['Algo'] == "PD"]);
ax1.legend([ "Fuerza Bruta","Meet in the Middle", "Prog. Dinamica"]);
plt.xlabel("N");
plt.ylabel("tiempo (ms)");


plt.show()