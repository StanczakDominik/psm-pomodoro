# Licznik pomodoro

Omawiane urządzenie jest sprzętową implementacją licznika Pomodoro na podstawie mikrokontrolera AVR ATmega32.

### Funkcjonalność:
* Odmierzanie czasu pracy oraz czasu przerwy w pracy w trosce o wydajność, produktywność, zdrowie, dobre samopoczucie i satysfakcję życiową użytkownika końcowego
* Czytelny wyświetlacz LED [NAZWA_LCD] pozwala na zorientowanie się w obecnej sytuacji w mgnieniu oka.
    * Może wyświetlać śladowe ilości chińskich krzaczków.
* Subtelne powiadomienie starannie dobranym czasem trwania dźwięku bzyczka oraz zapaleniem diody o nadejściu czasu na przejście do kolejnej fazy pracy
* Obsługa stanu flow - użytkownik sam wybiera, kiedy chce rozpocząć przerwę lub wrócić do pracy
* Możliwość ręcznego ustawiania czasu pracy lub przerwy z poziomu komputera użytkownika poprzez interfejs RS232C USART
    * Aż `0b10` komend!
    * Możliwość ustawienia czasu pracy i czasu przerwy w zakresie do jednej godziny, co daje aż 12 milionów możliwych trybów poprawnej pracy
        * I prawdopodobnie **NIESKOŃCZONĄ LICZBĘ TRYBÓW PRACY** uwzględniając wszystkie sposoby, w jaki program może się wykrzaczyć!
* Pomiar czasu zrealizowany bez używania liczników mikrokontrolera przy użyciu zegara [NAZWA_CLK] w celu poprawy niezawodności, zwiększenia niezawodności działania urządzenia oraz uniknięcia konieczności myślenia nad preskalerem!

### Kod programu
W pełni opensource'owy, dostępny na [repozytorium GitHub www.github.com/StanczakDominik/psm_pomodoro](www.github.com/StanczakDominik/psm_pomodoro).

### Wykorzystane elementy
1. Mikrokontroler AVR ATmega32
2. Zegar [NAZWA_CLK]
3. Wyświetlacz LED [NAZWA_LED]
4. Bzyczek [NAZWA_SPK]
5. Dioda LED (sztuk 1)

### Schemat urządzenia
