#! /usr/bin/env python3

from collections import defaultdict
from queue import Queue

def fuck() -> float:
    rates_txt = input().rstrip()
    start = input().rstrip()
    end = input().rstrip()
    adj = defaultdict(dict)
    vertices = set()
    d = dict()
    Q = Queue()
    for rate_txt in rates_txt.split(';'):
        r = rate_txt.split(',')
        vertices.add(r[0])
        vertices.add(r[1])
        adj[r[0]][r[1]] = float(r[2])
    if (start not in vertices) or (end not in vertices):
        print("Bad input!")
        return -1.0
    for v in vertices:
        d[v] = -1.0
    d[start] = 1.0
    Q.put(start)
    while not Q.empty():
        v = Q.get_nowait()
        for neighbor in adj[v]:
            if d[v]*adj[v][neighbor] > d[neighbor]:
                d[neighbor] = d[v]*adj[v][neighbor]
                Q.put(neighbor)
    return d[end]

print(fuck())