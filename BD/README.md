# LAB-1
## Выполнили:
**19 ПИ - 2**
* ***Конина Татьяна*** 
* ***Ожиганова Полина***

# Вариант I

### № 1. 
	Дана схема базы данных в виде следующих отношений.  С помощью операторов SQL создать логическую структуру 
    соответствующих таблиц для хранения в СУБД, используя известные средства поддержания целостности (NOT NULL,
     UNIQUE, и т.д.). Обосновать выбор типов данных и используемые средства поддержания целостности. При выборе 
     подходящих типов данных использовать информацию о конкретных значениях полей БД (см. прил.1)
	
	ПОКУПАТЕЛЬ
	ИДЕНТИФИКАТОР 		ФАМИЛИЯ		 РАЙОН ПРОЖИВАНИЯ 		СКИДКА, %
	
	МАГАЗИН
	ИДЕНТИФИКАТОР 		НАЗВАНИЕ 		РАЙОН РАЗМЕЩЕНИЯ 		КОММИСИОННЫЕ % 
	
	КНИГИ
	ИДЕНТИФИКАТОР 		НАЗВАНИЕ 		СТОИМОСТЬ, РУБ. 		СКЛАД 		КОЛ-ВО 
	
	ПОКУПКА
	НОМЕР ЗАКАЗА 		ДАТА 		ПРОДАВЕЦ 		ПОКУПАТЕЛЬ 		КНИГА		КОЛ-ВО 		СУММА, РУБ 

```sql
CREATE TABLE buyer (
id SERIAL PRIMARY KEY, -- индетификатор
surname text NOT NULL, -- фамилия (строка)
district text NOT NULL, -- район проживания(строка)
discount integer NOT NULL,CHECK (discount >=0) --скидка (не может быть больше 0)
);

CREATE TABLE shop (
id SERIAL PRIMARY KEY, -- индетификатор
name text NOT NULL, --
district text NOT NULL,
commission_fees integer NOT NULL, CHECK(commission_fees >= 0)
);

CREATE TABLE books (
id SERIAL PRIMARY KEY, -- индетификатор
title text NOT NULL,
price integer NOT NULL, CHECK(price >= 0),
repo text NOT NULL,
quantity integer NOT NULL,CHECK(quantity >= 0)
);

CREATE TABLE purchase (
order_number SERIAL PRIMARY KEY,
month text NOT NULL,
seller integer NOT NULL,CHECK (seller >=0),
buyer integer NOT NULL,CHECK (buyer >=0),
book integer NOT NULL,CHECK (book >= 0),
quantity integer NOT NULL,CHECK (quantity >=0),
price integer NOT NULL
);
```
<p align="left">
  <img src="https://i.imgur.com/f1XVyvj.png" width="600">
</p>
<p align="left">
  <img src="https://i.imgur.com/zHfTRPt.png" width="600">
</p>

### № 2.
	Ввести в ранее созданные таблицы конкретные данные (см. прил. 1). Использовать скрипт-файл из операторов INSERT 
    или вспомогательную утилиту .
```sql
INSERT INTO buyer 
(id, surname, district ,discount) 
VALUES
(001, 'Сидоров' ,'Нижегородский',10),
(002,'Потапов','Советский',20),
(003,'Попов','Ленинский',10),
(004,'Романова','Нижегородский',10),
(005,'Миронов','Автозаводский',15),
(006,'Попов','Советский',0);
```
<p align="left">
  <img src="https://i.imgur.com/PCfIioC.png" width="600">
</p>

```sql
INSERT INTO shop 
(id, name,district, commission_fees) 
VALUES 
(001,'Знание','Автозаводский',7),
(002,'Наука','Нижегородский',8),
(003,'Книжный мир','Приокский',6),
(004,'Книги','Сормовский',9),
(005,'Книги','Советский',7)
```
<p align="left">
  <img src="https://i.imgur.com/XPQH5lr.png" width="600">
</p>

```sql
INSERT INTO books 
(id, title,price,repo,quantity) VALUES
(001,'Windows для чайников',15000,'Сормовский',400),
(002,'Excel 5.0',23000,'Сормовский',360),
(003,'Работа с Visual FoxPro',32000,'Нижегородский',300),
(004,'Программирование в среде Delphi',20000,'Нижегородский',100),
(005,'SQL',47000,'Автозаводский',89),
(006,'Word 6.0 для Windows',16000,'Сормовский',200),
(007,'Твой первый выход в Internet',15000,'Советский',140)
```
<p align="left">
  <img src="https://i.imgur.com/gbCV4yF.png" width="600">
</p>

```sql
INSERT INTO purchase (order_number,month,seller,buyer,book,quantity,price)
VALUES
(10011,'Январь',001,006,003,2,64000),
(10012, 'Январь',001,006,002,2,46000),
(10013,'Январь',005,005,004,4,80000),
(10014,'Февраль',001,003,003,3,96000),
(10015,'Февраль',004,006,002,1,23000),
(10016,'Март',001,004,007,2,30000),
(10017,'Март',005,006,006,3,48000),
(10018,'Апрель',001,001,003,3,96000),
(10019,'Апрель',003,003,007,2,30000),
(10020,'Апрель',005,002,002,5,115000),
(10021,'Апрель',005,002,001,3,45000),
(10022,'Май',002,003,007,2,30000),
(10023,'Май',002,004,003,1,32000),
(10024,'Май',004,003,005,1,47000),
(10025,'Май',004,006,003,4,60000),
(10026,'Май',005,001,005,3,80000),
(10027,'Июнь',003,002,006,2,32000)
```
<p align="left">
  <img src="https://i.imgur.com/3iSEk7U.png" width="600">
</p>

### № 3.
	Используя оператор SELECT создать запрос для вывода всех строк каждой таблицы. Проверить правильность ввода.
	При необходимости произвести коррекцию значений операторами INSERT, UPDATE, DELETE. 
```sql
SELECT LPAD(id::text,3,'0') as id,surname,district,discount from buyer
```
<p align="left">
  <img src="https://i.imgur.com/fwisovu.png" width="600">
</p>

```sql
SELECT LPAD(id::text,3,'0') as id, name,district, commission_fees from shop
```
<p align="left">
  <img src="https://i.imgur.com/57FsCTO.png" width="600">
</p>

```sql
SELECT LPAD(id::text,3,'0') as id, title,price,repo,quantity from books
```

<p align="left">
  <img src="https://i.imgur.com/dQtSw47.png" width="600">
</p>

```sql
SELECT order_number,month, LPAD(seller::text,3,'0') as seller, LPAD(buyer::text,3,'0') as buyer,
LPAD (book::text,3,'0') as book, quantity,price from purchase
```

<p align="left">
  <img src="https://i.imgur.com/AEcOGq9.png" width="600">
</p>

## или

<p align="left">
  <img src="https://i.imgur.com/diraYUM.png" width="600">
</p>

<p align="left">
  <img src="https://i.imgur.com/TMRfP6k.png" width="600">
</p>

<p align="left">
  <img src="https://imgur.com/A3ZNRBD.png" width="600">
</p>

<p align="left">
  <img src="https://imgur.com/bt08gIL.png" width="600">
</p>

### № 4.
	Создать запросы для вывода: 
a) всех различных названий и стоимостей книг;
```sql
SELECT title, price
FROM books;
```
<p align="left">
  <img src="https://imgur.com/datu2uW.png" width="600">
</p>

b) всех различных районов, в которых проживают покупатели;
```sql
SELECT district
FROM buyer; 
```
<p align="left">
  <img src="https://imgur.com/jlRQpcQ.png" width="600">
</p>

c) всех различных месяцев, когда производились покупки;
```sql
SELECT month
FROM purchase; 
```
<p align="left">
  <img src="https://imgur.com/XR6njm0.png" width="600">
</p>

### № 5.
	Создать запросы для получения инорфмации о: 
a) фамилиях и размере скидки всех покупателей, проживающих в Нижегородском районе;
```sql
SELECT surname, discount
FROM buyer
WHERE district = 'Нижегородский';
```
<p align="left">
  <img src="https://imgur.com/YzAdsIq.png" width="600">
</p>

b) названиях магазинов Сормовского или Советского районов;
```sql
SELECT name
FROM shop
WHERE district = 'Сормовский' or district = 'Советский';
```
<p align="left">
  <img src="https://imgur.com/VEnGUzF.png" width="600">
</p>

c) Названиях  и стоимости книг, в которых встречается слово Windows, или стоящих более 20000 руб.
   Вывод результатов организовать по названию и убыванию цены книг;
```sql
SELECT title, price
FROM books
WHERE title LIKE '%Windows%' or price > 20000
ORDER BY  price DESC 
```
<p align="left">
  <img src="https://imgur.com/9U4winu.png" width="600">
</p>

### № 6.
	Для каждой покупки вывести следующие данные:
a)  фамилию покупателя и название магазина, где производилась покупка;
```sql
SELECT distinct order_number, title as BookName, purchase.buyer as bID, surname, name as ShopName
from buyer,shop,purchase,books
where buyer.id=purchase.buyer and purchase.seller=shop.id 
and purchase.book = books.id and purchase.buyer = buyer.id
```
<p align="left">
  <img src="https://i.imgur.com/MPjbzoS.png" width="600">
</p>

b) дату, фамилию покупателя, скидку, название и количество купленных книг;
```sql
SELECT title,month,surname,discount,purchase.quantity as quantity from purchase,buyer,books
where purchase.buyer=buyer.id and books.id=purchase.book
```
<p align="left">
  <img src="https://imgur.com/LbXjDrc.png" width="600">
</p>

### № 7.
	Определить:
a)	номер заказа, фамилию покупателя и дату для покупок в которых было продано книг на сумму не меньшую чем 60000 руб.
```sql
SELECT order_number,surname,month from purchase,buyer
where purchase.price > 60000 and buyer.id = purchase.buyer
```
<p align="left">
  <img src="https://i.imgur.com/O7UTVK2.png" width="600">
</p>

b)	покупки, сделанные покупателем в своем районе не ранее марта месяца.
    Вывести фамилию покупателя, район, дату. Произвести сортировку;
```sql
SELECT distinct surname,month,shop.district as district 
from purchase,shop,buyer
where buyer.district = shop.district 
and purchase.buyer = buyer.id and purchase.seller = shop.id
and (purchase.month ='Март' or purchase.month = 'Апрель'
or purchase.month = 'Май' or purchase.month = 'Июнь')
ORDER BY surname 
```
<p align="left">
  <img src="https://i.imgur.com/AiDNckZ.png" width="600">
</p>

c)	магазины, расположенные в любом районе, кроме Автозаводского, где покупали книги те, у кого скидка от 10 до 15 %;
```sql
SELECT distinct name,  shop.id
FROM purchase, shop, buyer
WHERE purchase.buyer = buyer.id
and purchase.seller = shop.id
and shop.district != 'Автозаводский' 
and buyer.discount BETWEEN 10 AND 15
```
<p align="left">
  <img src="https://i.imgur.com/yCtLlr8.png" width="600">
</p>

d)	данные по покупке книг (название, район складирования, количество), приобретенных в районе складирования
    и содержащихся в запасе более 10 штук. 
    Включить данные о стоимости и отсортировать по возрастанию;
```sql
SELECT DISTINCT books.title, books.price, books.repo, purchase.quantity 
FROM books, purchase, shop
WHERE purchase.book = books.id  -- район складирования 
and purchase.seller = shop.id  -- район складирования 
and books.quantity > 10 
ORDER BY books.price ASC
```
<p align="left">
  <img src="https://imgur.com/DoKNgm3.png" width="600">
</p>

### № 8.
	Создать запрос для модификации всех значений столбца с суммарной величиной покупки, 
	чтобы он содержал истинную сумму, оплачиваемую покупателем ( с учетом скидки). 
    Вывести новые значения.
```sql
update purchase set price = purchase.price * (100 - buyer.discount)/100
from buyer where purchase.buyer = buyer.id;
SELECT order_number,month, LPAD(seller::text,3,'0') as seller, LPAD(buyer::text,3,'0') as buyer,
LPAD (book::text,3,'0') as book, quantity,price from purchase
```
<p align="left">
  <img src="https://imgur.com/HoKdgD2.png" width="600">
</p>

### № 9.
	Расширить таблицу с данными о покупке столбцом, содержащим величину коммисионных, получаемых магазином. 
    Создать запрос для ввода конкретных значений во все строки таблицы покупок.
```sql
ALTER TABLE purchase ADD commission_fees integer CHECK (commission_fees >= 0);
UPDATE purchase SET commission_fees = (SELECT shop.commission_fees FROM shop WHERE shop.id = purchase.seller);
	
SELECT * FROM purchase  -- проверка
```
<p align="left">
  <img src="https://i.imgur.com/o07GlaS.png" width="600">
</p>

## Уровень 2.

### № 10.
	Используя операцию IN (NOT IN)  реализовать следующие запросы:
a)	найти покупателей, которые не покупали книг в магазинах Нижегородского района в июне месяце;
```sql
select * 
from buyer
where id not in (select buyer from purchase where month in ('Июнь'))
```
<p align="left">
  <img src="https://imgur.com/ebZsQlk.png" width="600">
</p>

b)	найти покупателей, покупавших книги в мае на сумму, меньшую чем купил Потапов в том же месяце;
```sql
SELECT t.surname, t.sum1 as p_sum, month
FROM
(SELECT surname, SUM(price * quantity) sum1
FROM  purchase, buyer, shop
WHERE purchase.buyer = buyer.id
and purchase.month IN ('Апрель')
AND purchase.seller=shop.id
GROUP BY surname, buyer.id )t, purchase, buyer
where t.sum1 < (select distinct SUM(price * quantity)
			   from purchase
			   where purchase.buyer = 2
			   and purchase.month IN ('Апрель'))
and purchase.buyer = buyer.id
and purchase.month in ('Апрель')
GROUP BY t.surname, p_sum, month
```
<p align="left">
  <img src="https://i.imgur.com/GAwShq0.png" width="600">
</p>

* Проверка, что у Потапова цена в апреле была выше.
```sql
select distinct buyer.id, buyer.surname,
				SUM(price * quantity), month
from purchase, buyer
where purchase.buyer = 2
and purchase.buyer = buyer.id
and purchase.month IN ('Апрель')
GROUP BY buyer.id, surname, month
```
<p align="left">
  <img src="https://i.imgur.com/ls3Swe3.png" width="600">
</p>

c)	реализовать запросы заданий 7.а, 7.с.
```sql
-- (7a)
SELECT distinct order_number, surname , month from purchase,buyer
where purchase.price > 60000 and surname in (select surname from buyer where buyer.id = purchase.buyer);
```
<p align="left">
  <img src="https://imgur.com/dASlhJ7.png" width="600">
</p>

```sql
-- (7c)
select * from shop where id in
(select shop.id as id from shop,purchase,buyer
where buyer.discount >= 10 and buyer.discount <= 15 
and shop.district != 'Автозаводский') 
```
<p align="left">
  <img src="https://i.imgur.com/6wJERf5.png" width="600">
</p>

### № 11.
	Используя операции ALL-ANY реализовать следующие запросы:
a)	определить покупателя, имеющего минимальную скидку среди тех, кто покупал книги на сумму не менее 50000руб.
```sql
SELECT *
FROM buyer
WHERE discount = ALL (SELECT MIN(discount)
		      FROM buyer)
		  AND id IN (SELECT purchase.buyer
			     FROM purchase
			     WHERE purchase.buyer = buyer.id
			     AND purchase.price >= 50000)
```
<p align="left">
  <img src="https://imgur.com/YcguBvN.png" width="600">
</p>

b)	найти покупателя, покупавшего самое большое количество книг;
```sql
SELECT t.surname, max(t.amount) as Highest
   FROM (
    SELECT surname, SUM(quantity) amount
    from purchase, buyer	
	where purchase.buyer = ALL(select purchase.buyer
				   from purchase 
				   where purchase.buyer = buyer.id)
	group by surname, buyer.id
  )t
  group by t.surname
 order by Highest desc
 limit 1
```
<p align="left">
  <img src="https://imgur.com/wKBxNO2.png" width="600">
</p>

c)	запрос задания 7.b;
```sql
SELECT distinct surname, month, shop.district AS district 
FROM purchase,shop,buyer
WHERE buyer.district = ANY(SELECT district
			   FROM buyer
			   WHERE buyer.district = shop.district) 
AND purchase.buyer = buyer.id
AND purchase.seller = shop.id
AND purchase.month = ANY(SELECT month
			 FROM purchase
			 WHERE purchase.month ='Март' or purchase.month = 'Апрель'
			 or purchase.month = 'Май' or purchase.month = 'Июнь')
ORDER BY surname 
```
<p align="left">
  <img src="https://i.imgur.com/LeL7gjE.png" width="600">
</p>

d)	какой из покупателей не покупавший книг в магазинах своего района, делал покупки на минимальную сумму.
```sql
SELECT t.surname, MIN(t.sum1) AS Lowest
FROM
(SELECT surname, SUM(price * quantity) sum1
FROM  purchase, buyer, shop
WHERE purchase.buyer = ALL(SELECT purchase.buyer
			FROM purchase 
			WHERE purchase.buyer = buyer.id)
AND purchase.seller=shop.id
AND buyer.district != shop.district
GROUP BY surname, buyer.id )t, purchase, buyer
GROUP BY t.surname
ORDER BY Lowest ASC
LIMIT 1
```
<p align="left">
  <img src="https://imgur.com/bdAGXdO.png" width="600">
</p>

### № 12.
    Используя операцию UNION получить районы проживания покупателей и районы складирования книг.
```sql
select district from buyer
union
select repo from books
```
<p align="left">
  <img src="https://imgur.com/gYh7qxg.png" width="600">
</p>

### № 13.
    Используя операцию EXISTS ( NOT EXISTS ) реализовать нижеследующие запросы.
    В случае, если для текущего состояния БД запрос будет выдавать пустое множество строк, требуется указать какие добавления в БД необходимо провести.
a)	какой покупатель покупал все книги в магазине “Наука” или “Знание”;
```sql
SELECT distinct buyer
FROM purchase as buyer_id
WHERE EXISTS (
SELECT *
FROM purchase where buyer_id.buyer not in
(SELECT purchase.buyer
FROM purchase
WHERE purchase.seller != 1 and seller != 2))
```
<p align="left">
  <img src="https://i.imgur.com/LAMK1hV.png" width="600">
</p>

b)	найти покупателей, покупавших книги во всех магазинах своего района до декабря;  
**!!!** До апреля не включительно ( в задании написан декабрь, но его нет в списке)  
   PS: вы разорешили выбрать другой месяц.**!!!**
```sql
SELECT distinct buyer
FROM purchase as buyer_id
WHERE NOT EXISTS (
			SELECT purchase.buyer
			FROM purchase
			where buyer_id.buyer 
	not in
	
			(SELECT purchase.buyer
			FROM purchase, buyer, shop
			WHERE purchase.buyer = buyer.id
			AND purchase.seller = shop.id
			AND buyer.district = shop.district
			and (purchase.month = 'Январь'
			or purchase.month = 'Февраль'
			or purchase.month = 'Март')))
```
<p align="left">
  <img src="https://i.imgur.com/tHE2Bqo.png" width="600">
</p>

c)	определить покупателей, покупавших все книги, не продающиеся в магазине с максимальным значением комиссионных;
```sql
SELECT distinct buyer
FROM purchase as buyer_id
WHERE EXISTS (
SELECT distinct purchase.buyer
        	FROM purchase
       	where buyer_id.buyer
   		not in
(select purchase.buyer from purchase where commission_fees = (
   SELECT MAX (commission_fees)
   FROM shop
) ))
```
<p align="left">
  <img src="https://i.imgur.com/DHqEdW4.png" width="600">
</p>

d)	найти среди покупателей тех, кто не покупал в мае книг со ценой более 25000 руб.
(покупали в мае на сумму менее 25000) в магазинах с максимальным размером комиссионных.
```sql
SELECT distinct buyer
FROM purchase as buyer_id
WHERE EXISTS (
SELECT distinct purchase.buyer
        	FROM purchase
       	where buyer_id.buyer
       	in
(select purchase.buyer from purchase where commission_fees = (
   SELECT MAX (commission_fees)
   FROM shop
) and purchase.price < 25000 and purchase.month = 'Май'))
```
<p align="left">
  <img src="https://i.imgur.com/BHgkeYu.png" width="600">
</p>

**Запрос оказался пустым.**  
Вставим строку, где покупатель с id 6  купит в мае на сумму менее 25000(24000) в магазине с максимальными комиссионными (9)
```sql 
insert into purchase
(order_number,month,seller,buyer,book,quantity,price,commission_fees)
VALUES
(10028,'Май',001,006,003,2,24000,9)
```
<p align="left">
  <img src="https://i.imgur.com/sOYXPjg.png" width="600">
</p>

### Проверка
**Повторим запрос**
<p align="left">
  <img src="https://i.imgur.com/cg4fK9b.png" width="600">
</p>


### № 14.
	Реализовать запросы с использованием аггрегатных функций:
a)	получить среднюю стоимость покупок, сделанных в магазинах Нижегородского района;
```sql
select avg(price) from purchase;
```
<p align="left">
  <img src="https://imgur.com/4ivmm3X.png" width="600">
</p>

b)	найти количество покупателей, покупавших книги в магазине “Наука”;
```sql
select count(buyer) from purchase,shop
where purchase.seller=shop.id and shop.name='Наука'
```
<p align="left">
  <img src="https://imgur.com/ngAmHsZ.png" width="300">
</p>

c)	найти покупателей имеющих скидку ниже средней;
```sql
select avg(discount) from buyer;
select * from buyer where discount > (select avg(discount) from buyer)
```
<p align="left">
  <img src="https://imgur.com/c5MoEcM.png" width="600">
</p>

d)	определить магазины, в которых покупало книги больше покупателей чем в магазине “Наука”;
```sql
select * from shop where id in (
SELECT seller from purchase
group by (seller) having count(*) > (select count(buyer) from purchase,shop
where purchase.seller=shop.id and shop.name='Наука'))
```
<p align="left">
  <img src="https://imgur.com/F289MiM.png" width="600">
</p>

### № 15.
    Используя средства группировки реализовать следующие запросы:
a)	вывести данные по суммарной стоимости книг, купленных в каждом магазине;
```sql
select name, SUM(price * quantity)
from shop,purchase,buyer
where purchase.seller=shop.id and purchase.buyer=buyer.id
group by name
```
<p align="left">
  <img src="https://imgur.com/gP5YLdW.png" width="600">
</p>

b)	вывести отчет о суммарной стоимости всех купленных книг по районам, где расположены магазины;
```sql
select shop.district, name, SUM(price * quantity) as district
from shop,purchase,buyer
where purchase.seller=shop.id and purchase.buyer=buyer.id
group by shop.district,name
```
<p align="left">
  <img src="https://imgur.com/5hCL2Oj.png" width="600">
</p>

c)	получить сводную информацию о сумме всех покупок, произведенных каждым покупателем;
```sql
select surname, SUM(price * quantity)
from purchase, buyer
where purchase.buyer=buyer.id
group by surname, buyer.id
```
<p align="left">
  <img src="https://imgur.com/Jlf0AT0.png" width="600">
</p>

d)	определить для каждого дня недели количество книг, купленных покупателями не из Советского района.  
**!!!** В задании написано "для каждого дня недели", 
   однако у нас в таблице представлены 
   только месяцы.**!!!**
```sql
select month, SUM(quantity) as amount
from purchase, shop
where purchase.seller = shop.id AND shop.district != 'Советский' 
group by month
```
<p align="left">
  <img src="https://imgur.com/4V3GoUm.png" width="600">
</p>
