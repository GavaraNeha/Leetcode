class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        mp = {e.id: e for e in employees}

        def dfs(x):
            total = mp[x].importance
            for sub in mp[x].subordinates:
                total += dfs(sub)
            return total

        return dfs(id)