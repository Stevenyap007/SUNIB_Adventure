-- https://anthonychandra.notion.site/Data-Manipulation-Language-6fc39ae75130467e8c450e3c0f20d2e2
--No 1
INSERT INTO customers(customer_id, customer_name, customer_gender, customer_address, customer_email, customer_dob) VALUES
(16, 'Joshua Josh', 'Male', '17 Anggrek Street', 'joshua.josh@binus.ac.id', '2003-01-01')

--No 2
-- Update fisherman_name from fisherman to 'Budi' for every fisherman whose transaction_date happen in 22 Juni 2002
UPDATE fishermen f JOIN transaction_headers th ON f.fisherman_id = th.fisherman_id
SET f.fisherman_name = 'Budi'
WHERE th.transaction_date = '2020-06-22'

--No 3
-- Display fish_name, fish_price, for every fish which fish_type_name is 'Tuna'
SELECT f.fish_name, 
f.fish_price
FROM fishes f JOIN fish_types ft ON f.fish_type_id = ft.fish_type_id
WHERE ft.fish_type_name = 'Tuna'

--No 4
--Delete from customers for every customer which transaction's quantity is less than 4. Then, rollback the deletion.
(Start Transaction, Rollback, ...)