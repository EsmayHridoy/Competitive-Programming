import java.util.Random;
import java.util.Scanner;

public class TwoStepVerification {
    public static void main(String[] args){
        // Simulated user registration
        String userID = "exampleUser";
        String userPhoneNumber = "+1234567890";

        // Generate and send verification code
        String verificationCode = generateVerificationCode();
        sendVerificationCode(userPhoneNumber, verificationCode);

        // Simulated user input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the verification code received on your phone: ");
        String userEnteredCode = scanner.nextLine();
        // Verify the code
        if(verifyCode(verificationCode, userEnteredCode)){
            System.out.println("Verification successfull. User is authenticated.");
        } else{
            System.out.println("Verification failed. User is not authenticated.");
        }
    }
    // Generate a random 6-digit verification code
    private static String generateVerificationCode() {
        Random random = new Random();
        // Generates a number between 100000 and 999999
        int code = 100000 + random.nextInt(900000);
        return String.valueOf(code);
    }
    // Simulate sending the verification code to the user's phone
    private static void sendVerificationCode(String phoneNumber, String verificationCode){
        System.out.println("Sending verification code to "+phoneNumber +": "+verificationCode);
    }
    // Verify the user-entered code with the generated code
    private static boolean verifyCode(String generatedCode, String userEnteredCode){
        return generatedCode.equals(userEnteredCode);
    }
} 