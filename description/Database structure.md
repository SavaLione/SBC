# Структура базы данных
## Таблица пользователей

|id|username|password|name|email|phone|role|registration_date|last_time_online|description|department|branch|is_user_active|registration_confirmation_code|city|
|--|--------|--------|----|-----|-----|----|-----------------|----------------|-----------|----------|------|--------------|------------------------------|----|
|  |        |        |    |     |     |    |                 |                |           |          |      |              |                              |    |

```
id - id пользователя
username - Логин
password - Пароль
name - ФИО
email - Адрес электронной почты
phone - Номер телефона
role - Роль в системе
registration_date - Дата регистрации
last_time_online - Последний раз в сети
description - Описание пользователя
department - Отдел
branch - Филиал
is_user_active - Активен пользователь? Есть доступ к системе?
registration_confirmation_code - Код подтверждения регистрации
city - Город
```

## Таблица с кодами
|id|code|time|user|
|--|----|----|----|
|  |    |    |    |

```
id - id пользователя
code - Код
time - Время
user - username - Логин
```

# Запросы к базам данных
## Запрос на создание таблицы с пользователями
### users
#### sqlite
```sql
CREATE TABLE IF NOT EXISTS "users" (
	"id"	INTEGER NOT NULL PRIMARY KEY UNIQUE,
	"username"	TEXT NOT NULL UNIQUE,
	"password"	TEXT NOT NULL,
	"name" TEXT,
	"email"	TEXT,
	"phone"	TEXT,
	"role"	TEXT,
	"registration_date"	TEXT,
	"last_time_online"	TEXT,
	"description"	TEXT,
	"department"	TEXT,
	"branch"	TEXT,
	"is_user_active"	TEXT,
	"registration_confirmation_code"	TEXT,
	"city"	TEXT
);
```

```
AUTOINCREMENT - при INTEGER PRIMARY KEY, ячейка будет автоматически AUTOINCREMENT
```