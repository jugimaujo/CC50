-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Query the description of the crime in question to understand better what happened
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2020 AND street = "Chamberlin Street";

-- It happened at 10:15am at the Chamberlin Street courthouse. I need to check what the
-- three present witnesses at the time told about what happened in the theft

-- Checking the transcript and name of the witnesses of the theft
SELECT name, transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2020;

-- Witnesses interviews transcripts:
-- | Ruth said, sometime within ten minutes of the theft, the thief got into a car in the
-- courthouse parking lot and drove away. 
-- | Eugene told the thief was earlier that morning at the ATM on Fifer Street withdrawing money.
-- | Raymond told the thief called someone when it was leaving the courthouse. They were
-- talking about they taking the earliest flight out of Fiftyville in the next day (29/07/2020).
-- The thief asked to the other one in the call to buy the flight ticket.

-- Let's check some courthouse security logs of the activity and license plate to see what I can find
SELECT license_plate, activity, hour, minute FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28 
AND hour = 10 AND (minute >= 15 AND minute <= 25);

-- The the cars with those license plates which exited the parking lot were:
-- 5P2BI95(10:16), 94KL13X(10:18), 6P58WS2(10:18), 4328GD8(10:19), G412CB7(10:20),
-- L93JTIZ(10:21), 322W7JE(10:23), 0NTHK55(10:23)

-- Using the atm transactions on Fifer Street in that day to get to the suspect people's name
SELECT name, license_plate, phone_number FROM atm_transactions AS at
JOIN bank_accounts ON at.account_number = bank_accounts.account_number
JOIN people ON people.id = bank_accounts.person_id
WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs
                        WHERE year = 2020 AND month = 7 AND day = 28 
                        AND hour = 10 AND (minute >= 15 AND minute <= 25))
AND atm_location LIKE "Fifer Street" AND day = 28 AND month = 7 AND year = 2020;

-- According to the results, the suspects and each one's license_plates are:
-- Ernest (94KL13X), Russell (322W7JE), Elizabeth (L93JTIZ) and Danielle (4328GD8)

-- Now, I will search for informations from the Raymond's interview

-- First, I'll look through the phone calls in the number of each suspect
SELECT name AS caller_name, phone_number FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE day = 28 AND month = 7 AND year = 2020
AND name IN (SELECT name FROM atm_transactions AS at
            JOIN bank_accounts ON at.account_number = bank_accounts.account_number
            JOIN people ON people.id = bank_accounts.person_id
            WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs
                                    WHERE year = 2020 AND month = 7 AND day = 28 
                                    AND hour = 10 AND (minute >= 15 AND minute <= 25))
            AND atm_location LIKE "Fifer Street" AND day = 28 AND month = 7 AND year = 2020);

-- Now, checking the possible Accomplices, who talked to the thief for less than a minute 
SELECT name AS receiver_name, phone_number, caller, duration FROM phone_calls
JOIN people ON people.phone_number = phone_calls.receiver
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60
AND caller IN (SELECT phone_number FROM phone_calls
            JOIN people ON people.phone_number = phone_calls.caller
            WHERE day = 28 AND month = 7 AND year = 2020
            AND name IN (SELECT name FROM atm_transactions AS at
                        JOIN bank_accounts ON at.account_number = bank_accounts.account_number
                        JOIN people ON people.id = bank_accounts.person_id
                        WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs
                                                WHERE year = 2020 AND month = 7 AND day = 28 
                                                AND hour = 10 AND (minute >= 15 AND minute <= 25))
                        AND atm_location LIKE "Fifer Street" AND day = 28 AND month = 7 AND year = 2020));

    -- According to the first query, the suspect list now points to 
    -- Ernest ((367) 555-5533) and Russell ((770) 555-1861)

    -- The second query shows the accomplice may be:
    -- If the thief is Ernest: Berthold
    -- If the thief is Russell: Philip
    
-- Then, it's time to use info from the flight they planned.
SELECT name, city, hour, minute FROM people AS p
JOIN passengers ON passengers.passport_number = p.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON airports.id = flights.destination_airport_id
WHERE name IN ("Russell", "Ernest", "Berthold", "Philip")
AND day = 29 AND month = 7 AND year = 2020;

-- Finally, checking that the earliest flight was from Fiftyville to London,
-- I assure that the Thief was Ernest, and his Accomplpice was Berthold.
