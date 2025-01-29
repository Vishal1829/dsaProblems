#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
 
    return true;
}

// Function to generate a random prime number
int generateRandomPrime(int min, int max) {
    int candidate;
    do {
        candidate = rand() % (max - min + 1) + min;
    } while (!isPrime(candidate));
    return candidate;
}

// Function to perform modular exponentiation (a^b mod m)
int modExp(int base, int exponent, int modulus) {
    if (modulus == 1) return 0;

    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}


// Function to find a primitive root modulo p
int findPrimitiveRoot(int p) {
    for (int g = 2; g < p; ++g) {
        bool isPrimitiveRoot = true;
        for (int i = 1; i <= p - 2; ++i) {
            if (modExp(g, i, p) == 1) {
                isPrimitiveRoot = false;
                break;
            }
        }
        if (isPrimitiveRoot) return g;
    }
    return -1; // No primitive root found (should not happen for large p)
}

int main() {
    srand(time(nullptr));

    // Generate a random prime number for p
    int p = generateRandomPrime(10000, 50000);

    // Find a primitive root modulo p
    int g = findPrimitiveRoot(p);


    // Generate random private keys for Alice and Bob
    int privateAlice = rand() % (p - 1) + 1; // 1 <= privateAlice < p
    int privateBob = rand() % (p - 1) + 1;   // 1 <= privateBob < p


    // Calculate public keys
    int publicAlice = modExp(g, privateAlice, p);
    int publicBob = modExp(g, privateBob, p);


    // Simulate exchange of public keys (in a real scenario, use secure channels)
    int exchangedPublicAlice = publicBob;
    int exchangedPublicBob = publicAlice;

    
    // Calculate shared secret using exchanged public keys
    int sharedSecretAlice = modExp(exchangedPublicAlice, privateAlice, p);
    int sharedSecretBob = modExp(exchangedPublicBob, privateBob, p);


    // Ensure that both parties have the same shared secret
    if (sharedSecretAlice != sharedSecretBob) {
        std::cerr << "Shared secret mismatch." << std::endl;
        return 1;
    }

    // Display the shared secret
    std::cout << "Shared Secret: " << sharedSecretAlice << std::endl;

    std::ifstream inputFile("input.xml");
    std::string xmlContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    // Encrypt the XML content using the shared secret
    std::string encryptedXML;
    for (size_t i = 0; i < xmlContent.length(); ++i) {
        encryptedXML += xmlContent[i] ^ sharedSecretAlice;
    }

    // Write the encrypted XML content to a file
    std::ofstream encryptedFile("encrypted.xml");
    encryptedFile << encryptedXML;
    encryptedFile.close();

    std::cout << "XML Encrypted and saved to encrypted.xml" << std::endl;

    // Decrypt the encrypted XML content using the shared secret
    std::string decryptedXML;
    for (size_t i = 0; i < encryptedXML.length(); ++i) {
        decryptedXML += encryptedXML[i] ^ sharedSecretAlice;
    }

    // Write the decrypted XML content to a file
    std::ofstream decryptedFile("decrypted.xml");
    decryptedFile << decryptedXML;
    decryptedFile.close();

    std::cout << "XML Decrypted and saved to decrypted.xml" << std::endl;

    // // Simulate plaintext data
    // std::string plaintext = "Hello, this is a secret message!";


    // // XOR each character of the plaintext with the shared secret
    // std::string ciphertext;
    // for (size_t i = 0; i < plaintext.length(); ++i) {
    //     ciphertext += plaintext[i] ^ sharedSecretAlice;
    // }

    // // Display the encrypted message
    // std::cout << "Encrypted Message: " << ciphertext << std::endl;

    // // Decrypt the message using the shared secret
    // std::string decryptedText;
    // for (size_t i = 0; i < ciphertext.length(); ++i) {
    //     decryptedText += ciphertext[i] ^ sharedSecretAlice;
    // }

    // // Display the decrypted message
    // std::cout << "Decrypted Message: " << decryptedText << std::endl;

    return 0;

}
