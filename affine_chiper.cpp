#include <bits/stdc++.h>
using namespace std;

//Nilai kunci dari a dan b
const int a = 17;
const int b = 20;

string encryptMessage(string msg)
{
    ///Teks Cipher awalnya kosong
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        // Hindari ruang untuk dienkripsi
        if (msg[i] != ' ')
            /* menerapkan rumus enkripsi (a x + b) mod m
            {dimana x adalah msg[i] dan m adalah 26} dan menambahkan 'A' ke
            membawanya dalam kisaran alfabet ASCII [ 65-90 | A-Z ] */
            cipher = cipher +
                     (char)((((a * (msg[i] - 'A')) + b) % 26) + 'A');
        else
            //hanya menambahkan karakter ruang
            cipher += msg[i];
    }
    return cipher;
}

string decryptCipher(string cipher)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;

    //Temukan a^-1 (invers perkalian a
    //dalam kelompok integer modulo m.)
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;

        //Periksa apakah (a*i)%26 == 1,
        //maka akan menjadi invers perkalian dari
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')
            /*Menerapkan rumus dekripsi a^-1 (x - b ) mod m
            {here x adalah cipher[i] dan m adalah 26} dan ditambahkan 'A'
            untuk membawanya dalam kisaran alfabet ASCII [ 65-90 | A-Z ] */
            msg = msg +
                  (char)(((a_inv * ((cipher[i] + 'A' - b)) % 26)) + 'A');
        else
            //hanya menambahkan karakter ruang
            msg += cipher[i];
    }

    return msg;
}

//Driver Program
int main(void)
{
    string msg = "RIDHO WALIDHAYIN RIFAI";

    //Memanggil fungsi enkripsi
    string cipherText = encryptMessage(msg);
    cout << "Encrypted Message is : " << cipherText << endl;

    //Memanggil funsi deskripsi
    cout << "Decrypted Message is: " << decryptCipher(cipherText);

    return 0;
}