import java.util.HashMap;

class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0;
        int cows = 0;

        HashMap<Character, Integer> count = new HashMap<>();

        // Count unmatched digits from secret
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) != guess.charAt(i)) {
                char s = secret.charAt(i);
                count.put(s, count.getOrDefault(s, 0) + 1);
            } else {
                bulls++;
            }
        }

        // Count cows
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) != guess.charAt(i)) {
                char g = guess.charAt(i);

                if (count.getOrDefault(g, 0) > 0) {
                    cows++;
                    count.put(g, count.get(g) - 1);
                }
            }
        }

        return bulls + "A" + cows + "B";
    }
}