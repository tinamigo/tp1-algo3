import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
sns.set()

df = pd.read_csv("fuerzaBruta50y100.csv")
#df["cota"] = df["N"] * (2**df["N"]);

print (df)

'''
df_cuadratico = pd.DataFrame({"N": [i for i in range(1, 31)], "Cota": [1.7e-5*i*(2**i) for i in range(1, 31)]});
ax1 = sns.lineplot(x="N", y="Tiempo", data=df);
ax1 = sns.lineplot(x="N", y="Cota", data=df_cuadratico);
ax1.legend(["FB", "1.7e-5 * Cota"]);
plt.ylabel("tiempo (ms)");
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
#df2 = pd.DataFrame({'IS':tuple(X), 'cota':tuple(Y)});
ax1 = sns.lmplot(x='Tiempo', y='cota', data=df);
plt.xlabel("T(n)");
plt.ylabel("cota(n)");

r = np.corrcoef(df["Tiempo"], df["cota"])[0, 1];
print("El coeficiente de correlación de Pearson es: r="+str(r))
'''

plt.show()