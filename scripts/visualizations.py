import numpy as np
import polars as pl
import seaborn as sns
import matplotlib.pyplot as plt

df = pl.read_csv("./data/linked_data.csv")
linked_df = df.filter(pl.col("set_type") == "Linked")
forest_df = df.filter(pl.col("set_type") == "Forest")
forest_rank_df = df.filter(pl.col("heuristic_type") == "Rank")

ax = sns.lineplot(
    data=linked_df, 
    hue="heuristic_type", x="n", y="duration_seconds",
    estimator="mean",
    palette="Set2"
)
ax.set_title(r'$m = 2n - 1$ Operations for $n$ elements runtime of a Linked List Disjoint Set')

min_n = linked_df.min().item(column="n", row=0)
max_n = linked_df.max().item(column="n", row=0)
temp_x = np.arange(min_n, max_n + min_n, step=min_n)
temp_y = 0.000001 * ((temp_x + temp_x - 1) + temp_x * np.log2(temp_x))
plt.plot(temp_x, temp_y, label=r'$0.000001(m + n \log_2 n))$', alpha=0.4)
plt.legend()
plt.savefig("./data/visualizations/linked_disjoint_sets.pdf")
plt.close()

ax = sns.lineplot(
    data=forest_df, 
    hue="heuristic_type", x="n", y="duration_seconds",
    estimator="mean",
    palette="Set2"
)
ax.set_title(r'$m = 2n - 1$ Operations for $n$ elements runtime of Forest Disjoint Set')

# temp_x = np.arange(min_n, max_n + min_n, step=min_n)
# temp_y = 0.000001 * ((temp_x + temp_x - 1) + temp_x * np.log2(temp_x))
# plt.plot(temp_x, temp_y, label=r'$0.000001(m + n \log_2 n))$', alpha=0.4)
# plt.legend()
plt.savefig("./data/visualizations/forest_disjoint_sets.pdf")
plt.close()

ax = sns.lineplot(
    data=forest_rank_df, 
    x="n", y="duration_seconds",
    estimator="mean",
    palette="Set2"
)
ax.set_title(r'Union-By-Rank & Path Compression Runtime Performance')
plt.savefig("./data/visualizations/rank_forest_disjoint_sets.pdf")
plt.close()