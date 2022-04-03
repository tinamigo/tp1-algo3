import numpy as np
import pandas as pd
import seaborn as sns
import math
import matplotlib.pyplot as plt
sns.set()

df = pd.read_csv("MitMpeorCasoExtendido.csv")
df["cota"] = df["N"] * (2**(df["N"]//2));



print (df)

ax1 = sns.lmplot(x = 'Tiempo', y = 'cota', data = df);
plt.xlabel("t(n)");
plt.ylabel("cota(n)");

r = np.corrcoef(df["Tiempo"], df["cota"])[0,1];
#ax1.legend(str(r))

print("El coeficiente de correlación de Pearson es: r="+str(r))

'''

# Graficamos el tiempo en función de n, con series variando m.
ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['W'] == 50]);
ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['W'] == 100]);
ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['W'] == 150]);
ax1 = sns.lineplot(x="N", y="Tiempo", data=df.loc[df['W'] == 200]);
ax1.legend(["W = 50", "W = 100", "W = 150", "W = 200"]);
plt.xlabel("N");
plt.ylabel("tiempo (ms)");
'''

plt.show()