class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        ans = []

        for word in words:
            w = word.lower()
            if all(c in rows[0] for c in w) or all(c in rows[1] for c in w) or all(c in rows[2] for c in w):
                ans.append(word)

        return ans