<?php
// Подключаем библиотеку RedBeanPHP
require "libs/rb-mysql.php";

// Подключаемся к БД
R::setup( 'mysql:host=192.168.1.70;dbname=test_mysql_db', 'test_mysql_user', 'Ba6ctHKSPPmvDtYXNg1EddBGiJ1uF8qp' );

// Проверка подключения к БД
if(!R::testConnection()) die('No DB connection!');

session_start(); // Создаем сессию для авторизации
?>