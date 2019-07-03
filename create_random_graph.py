import networkx as nx
import random

n = input()
m = input()
n = int(n)
m = int(m)

G = nx.random_powerlaw_tree(n, tries=999999)

edges = set(G.edges())
nodelist = list(G.nodes())

while(G.number_of_edges() < m):
    u, v = random.choices(nodelist, k=2)
    if (u,v) not in edges and (v,u) not in edges:
        G.add_edge(u,v)
        edges.add((u,v))
G = nx.connected_component_subgraphs(G).__next__()


print(n, m)
print(*random.choices(nodelist, k=2))
for u, v in G.edges():
    print(u,v, random.randrange(n))
