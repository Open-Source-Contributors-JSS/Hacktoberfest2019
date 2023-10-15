import java.util.Random;

public class KingCardPicker {
    public static void main(String[] args) {
        // Define arrays for suits and card values
        String[] suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
        String[] cardValues = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

        // Create a random number generator
        Random random = new Random();

        // Initialize a flag to check if a king card is found
        boolean foundKing = false;

        // Loop until a king card is picked
        while (!foundKing) {
            // Randomly select a suit and a card value
            int randomSuitIndex = random.nextInt(suits.length);
            int randomCardValueIndex = random.nextInt(cardValues.length);

            // Get the randomly selected card
            String randomSuit = suits[randomSuitIndex];
            String randomCardValue = cardValues[randomCardValueIndex];

            // Check if the card is a king
            if (randomCardValue.equals("King")) {
                foundKing = true;
                // Print the randomly picked king card
                System.out.println("Randomly picked king card: King of " + randomSuit);
            }
        }
    }
}
