/****************************************************************
  Bogstav-analyse — ultra-kommenteret (”pege-forklaring” til eksamen)
****************************************************************/

#include <iostream>   // cout/cin – al skærm-/tastatur-I-O
#include <string>     // std::string + std::getline til at læse hele linjer

//--------------------------------------------------------------
//  HJÆLPEFUNKTION:  toLowerAZ
//  Formål : Konverter ét tegn fra A-Z → a-z (ASCII +32); andre
//           tegn returneres uændret.
//--------------------------------------------------------------
char toLowerAZ(char ch)                             // modtager ét tegn
{
    if (ch >= 'A' && ch <= 'Z')                     // er det stort bogstav?
        return ch + ('a' - 'A');                   // ja ⇒ flyt 32 ned (65→97)
    return ch;                                      // nej ⇒ send tilbage som det er
}

//--------------------------------------------------------------
//  Dette er nok ift. eksamensopgaven, at forklare
//  HJÆLPEFUNKTION:  printFrequencies
//  Formål : Udskrive alfabetisk tabel for alle bogstaver, der
//           forekommer mindst én gang.
//
//  Hvad er en loop/løkke? “Gentag dette sæt instruktioner, så længe noget er sandt.”
//  Eksempler:
//  For            - 	Du kender præcis hvor mange gange (eller har et klart indeks).
//  While          - 	Gentag så længe noget er sandt (antal iterationer ukendt på forhånd).
//  do ... while   -  Skal altid køre mindst én gang, derefter teste.
//--------------------------------------------------------------
void printFrequencies(const int freq[26])           // const → funktionen ændrer IKKE arrayet
{
    std::cout << "\nBogstav  Antal\n";              // kolonne-overskrift
    for (int i = 0; i < 26; ++i)                    // loop a(0)…z(25)           for (int i = 1; i <= 5; ++i) = init i til 5, betegn i, derefter øg "step" med 1 (++i) 
    {                                               //                           i++ = øg i med én - dvs dette eksempel starter med 1, øges med ét step op til 5
        if (freq[i] > 0)                            // spring 0-forekomster over
        {
            char bogstav = static_cast<char>('a' + i); // i→bogstav                - Dette laver i om til bogstaver
            std::cout << bogstav << "        "      // juster mellemrum selv
                      << freq[i] << '\n';           // udskriv optælling
        }
    }
}

/********************  MAIN — programmet starter her  ********************/
int main()
{
    /* ---------- 1) INPUT  ---------------------------------------------------- */
    std::cout << "Indtast en tekstlinje:\n> ";      // prompt til bruger
    std::string tekst;                              // dynamisk streng-objekt
    std::getline(std::cin, tekst);                  // læs fuld linje inkl. mellemrum

    /* ---------- 2) INITIALISÉR TÆLLERE -------------------------------------- */
    int freq[26] = {0};                             // 26 heltal sat til 0: indeks 0=a, 25=z
    int total = 0;                                  // tæller alle gyldige bogstaver

    /* ---------- 3) LØKKE: NORMALISÉR + TÆL ---------------------------------- */
    for (size_t i = 0; i < tekst.size(); ++i)       // løb hele input-strengen igennem
    {
        char ch = toLowerAZ(tekst[i]);              // gør eventuelt stort → småt

        if (ch >= 'a' && ch <= 'z')                 // accepter kun a-z
        {
            ++freq[ch - 'a'];                       // bump den rette kasse i arrayet
            ++total;                                // bump samlet tæller
        }
    }

    /* ---------- 4) FIND MEST BRUGTE BOGSTAV --------------------------------- */
    int maxIdx = 0;                                 // start med 'a' som foreløbig vinder
    for (int i = 1; i < 26; ++i)                    // tjek resten af alfabetet
        if (freq[i] > freq[maxIdx])                 // bedre kandidat?
            maxIdx = i;                             // gem nyt indeks

    /* ---------- 5) OUTPUT TIL BRUGER --------------------------------------- */
    std::cout << "\nAntal bogstaver (uden mellemrum): "
              << total << '\n';                     // total tal
    std::cout << "Mest brugte bogstav: "
              << static_cast<char>('a' + maxIdx)    // indeks → bogstav
              << " (" << freq[maxIdx] << " gange)\n";

    printFrequencies(freq);                         // alfabetisk tabel (spring 0’er)

    return 0;                                       // alt OK
}