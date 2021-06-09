# OP_papildomaUzd

   1. Suskaičiuokite, kiek kartų kiekvienas skirtingas žodis pasikartoja Jūsų tekste. Tekstą galite paimti iš bet kur, pvz.: Vikipediją straipsnį apie Vilnių (Geriau kad būtu kitoks tekstas, ne mažiau 1000 žodžių). Tuomet realizacijos output'e (išoriniame faile) išveskite skirtingus žodžius (kableliai, taškai ir kiti skyrybos ženklai nėra žodžiu dalis!), kurie pasikartojo dažniau negu 1 kartą, o taip pat ir count'erį, nurodantį kiek kartų konkretus žodis pasikartojo.
   2. Sukurkite cross-reference tipo lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) kiekvienas iš daugiau negu vieną kartą pasikartojantis žodis buvo paminėtas.
   3. URL adresų suradimas Jūsų tekste. Kaip ir pirmos užduoties atveju, tekstą galite paimti iš bet kur, račiau būtina, kad tame tekste būtų bent keli URL'ai, pateikti "pilnu" https://www.vu.lt/ ar "sutrumpintu" pavidalu: www.vu.lt. Jūsų tikslas, iš to teksto išrinkti visus šiuos URL'us ir grąžiai atspausdinti ekrane (ar išvesti į failą)!
   4. Repozicija turi būti parengta pagal visus ankstesnių darbų galutinėms versijoms galiojančius reikalavimus.
## Programos pavyzdys
   ### Teksto failas 
   ```
   Seniausias parodos eksponatas – XVII a. antrosios pusės trijų Alytaus miesto bažnyčių inventorius. Taip pat bus rodomi ir XVII–XIX a. rankraščiai, susiję su Daugų, Punios ir Pivašiūnų bažnyčiomis.

Parodos lankytojų dėmesį ypatingai turėtų atkreipti XVIII a. Alytaus miesto magistrato dokumentas su pareigūnų parašais ir antspaudu, kurio centrinėje dalyje įkomponuotas miesto herbas – renesansinis skydas A.lt su www.vu.lt penkialape rože. Parodos svečiai išvys ir Alytaus krašto bažnyčiose klebonavusių 1918 m. vasario 16 d. Lietuvos Nepriklausomybės Akto signatarų Vlado Mirono ir Alfonso Petrulio autografus bei kitus su Alytaus miestu vu.lt susijusius dokumentus.

Parodoje bus rodomi rankraščiai, įtraukti į UNESCO programos „Pasaulio atmintis“ Lietuvos nacionalinį registrą. Tai – XVIII a. pradžios Vilniaus jėzuitų kolegijos dienoraštis ir XIX a. pradžios Simono Daukanto verstų pasakėčių autografas. Programos „Pasaulio atmintis“ tikslas – plačiai paskleisti žinią apie ypatingas valstybiniuose ir privačiuose archyvuose, muziejuose ir bibliotekose saugomas unikalių dokumentų kolekcijas.
   
   ```
   ### Rezultatas
   ```
...
   Programos || count=   1 || locations: 5 
      Punios || count=   1 || locations: 1 
  Seniausias || count=   1 || locations: 1 
      Simono || count=   1 || locations: 5 
         Tai || count=   1 || locations: 5 
        Taip || count=   1 || locations: 1 
      UNESCO || count=   1 || locations: 5 
    Vilniaus || count=   1 || locations: 5 
       Vlado || count=   1 || locations: 3 
         XIX || count=   1 || locations: 5 
        XVII || count=   1 || locations: 1 
       XVIII || count=   2 || locations: 3 5 
           a || count=   5 || locations: 1 1 3 5 5 
   antrosios || count=   1 || locations: 1 
   antspaudu || count=   1 || locations: 3 
        apie || count=   1 || locations: 5 
  archyvuose || count=   1 || locations: 5 
   atkreipti || count=   1 || locations: 3 
  autografas || count=   1 || locations: 5 
  autografus || count=   1 || locations: 3 
...
==========Links==========
A.lt
www.vu.lt
vu.lt
```
   

## Diegimo istrukcija
 1. Atsisiusti programos repozitorija
 2. Sukompiliuoti koda
 ```
      g++ main.cpp
 ```
 ## Paleidimo instrukcija 
   * ``` ./a.out ```
   * norint pakeisti skaitoma file  redaguogite input.txt arba main.cpp file pakeiskite fileName, pvz fileName = "myFile.txt"
  
