#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk enkripsi menggunakan Caesar Cipher
string caesar_encrypt(const string &text, int shift) {
    string encrypted_text = "";
    for (char ch : text) {
        // Cek jika karakter adalah huruf
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            // Enkripsi karakter dan tambahkan ke hasil
            encrypted_text += char(int(ch + shift - offset) % 26 + offset);
        } else {
            // Jika bukan huruf, tambahkan karakter tanpa perubahan
            encrypted_text += ch;
        }
    }
    return encrypted_text;
}

// Fungsi untuk dekripsi menggunakan Caesar Cipher
string caesar_decrypt(const string &text, int shift) {
    // Untuk dekripsi, cukup menggeser dengan arah yang berlawanan
    return caesar_encrypt(text, -shift);
}

int main() {
    string text;
    int shift;

    // Input dari pengguna
    cout << "Masukkan teks yang ingin dienkripsi: ";
    getline(cin, text);
    cout << "Masukkan jumlah pergeseran (1-25): ";
    cin >> shift;

    // Enkripsi
    string encrypted_text = caesar_encrypt(text, shift);
    cout << "Teks terenkripsi: " << encrypted_text << endl;

    // Dekripsi
    string decrypted_text = caesar_decrypt(encrypted_text, shift);
    cout << "Teks terdekripsi: " << decrypted_text << endl;

    return 0;
}

