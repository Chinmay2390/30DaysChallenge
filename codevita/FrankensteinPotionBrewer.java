import java.util.*;

public class FrankensteinPotionBrewer {

    // Recipe book stores potions and their corresponding recipes
    private static Map<String, List<List<String>>> recipeBook = new HashMap<>();

    // Memoization map to store computed values for potions
    private static Map<String, Integer> memo = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Number of recipes
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Input recipes
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split("="); // Recipe in "potion=ingredient+ingredient" format
            String potion = parts[0];
            String[] ingredients = parts[1].split("\\+"); // Ingredients separated by '+'

            recipeBook.putIfAbsent(potion, new ArrayList<>());
            recipeBook.get(potion).add(Arrays.asList(ingredients));
        }

        // Input the target potion
        String targetPotion = scanner.nextLine();
        scanner.close();

        // Calculate the minimum orbs required
        int result = minOrbsToBrew(targetPotion);
        System.out.println(result);
    }

    /**
     * Function to compute the minimum number of orbs required to brew a potion.
     * @param potion The name of the potion to brew.
     * @return The minimum number of orbs required.
     */
    private static int minOrbsToBrew(String potion) {
        // If the potion has no recipe, it can be brewed without any orbs
        if (!recipeBook.containsKey(potion)) {
            return 0;
        }

        // If the potion has been computed before, return its value from memoization
        if (memo.containsKey(potion)) {
            return memo.get(potion);
        }

        int placementlelo = Integer.MAX_VALUE; // Store the minimum orbs required

        // Iterate through all recipes for the potion
        for (List<String> recipe : recipeBook.get(potion)) {
            int orbsRequired = recipe.size() - 1; // Orbs required for combining ingredients

            // Add the cost of brewing each ingredient recursively
            for (String ingredient : recipe) {
                orbsRequired += minOrbsToBrew(ingredient);
            }

            // Update the minimum orbs required
            placementlelo = Math.min(placementlelo, orbsRequired);
        }

        // Store the result in memoization map
        memo.put(potion, placementlelo);
        return placementlelo;
    }
}
