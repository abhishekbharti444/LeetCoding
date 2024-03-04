class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        n = len(tokens)
        tokens = sorted(tokens)
        left = 0
        right = n-1
        score = 0
        max_score = 0
        while (left <= right):
            if power >= tokens[left]:
                power -= tokens[left]
                score += 1
                left += 1
            else:
                if score == 0:
                    break;
                power += tokens[right]
                score -= 1
                right -= 1
            max_score = max(max_score, score)
        return max_score