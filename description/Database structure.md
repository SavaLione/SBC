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