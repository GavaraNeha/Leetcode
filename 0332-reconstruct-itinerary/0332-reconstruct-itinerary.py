class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)

        for a, b in sorted(tickets, reverse=True):
            graph[a].append(b)

        ans = []

        def dfs(airport):
            while graph[airport]:
                dfs(graph[airport].pop())
            ans.append(airport)

        dfs("JFK")

        return ans[::-1]