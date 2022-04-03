import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
sns.set()

df1 = pd.read_csv("BTdistNormalInvFlaca.csv")
df2 = pd.read_csv("BTdistNormalFlaca.csv")
#df5 = pd.read_csv("BTdistUnif.csv")
#df6 = pd.read_csv("BTdesplazada.csv")
df2["diff"] = ((df2["Tiempo"] - df1["Tiempo"])/df2["Tiempo"])*100;

'''
ax1 = sns.lmplot(x = 'Tiempo', y = 'cota', data = df);
plt.xlabel("t(n)");
plt.ylabel("cota(n)");

r = np.corrcoef(df["Tiempo"], df["cota"])[0,1];
print("El coeficiente de correlación de Pearson es: r="+str(r))

'''

# Graficamos el tiempo en función de n, con series variando m.
#ax1 = sns.lineplot(x="N", y="Tiempo", data=df1);
ax1 = sns.lineplot(x="N", y="diff", data=df2);
#ax1 = sns.lineplot(x="N", y="Tiempo", data=df3);
#ax1 = sns.lineplot(x="N", y="Tiempo", data=df4);
#ax1 = sns.lineplot(x="N", y="Tiempo", data=df5);
#ax1 = sns.lineplot(x="N", y="Tiempo", data=df6);
#ax1.legend([""]);
plt.xlabel("N");
plt.ylabel("Diferencia Porcentual");


plt.show()