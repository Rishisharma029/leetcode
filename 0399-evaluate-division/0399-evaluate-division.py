from collections import defaultdict

class Solution:
    def calcEquation(self, equations, values, queries):
        graph = defaultdict(list)
        
        # Step 1: Build graph
        for (a, b), val in zip(equations, values):
            graph[a].append((b, val))
            graph[b].append((a, 1 / val))
        
        # Step 2: DFS function
        def dfs(src, target, visited):
            if src == target:
                return 1.0
            
            visited.add(src)
            
            for neighbor, value in graph[src]:
                if neighbor not in visited:
                    result = dfs(neighbor, target, visited)
                    if result != -1:
                        return result * value
            
            return -1
        
        # Step 3: Process queries
        results = []
        for c, d in queries:
            if c not in graph or d not in graph:
                results.append(-1.0)
            elif c == d:
                results.append(1.0)
            else:
                results.append(dfs(c, d, set()))
        
        return results