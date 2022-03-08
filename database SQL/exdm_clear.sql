-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Май 03 2016 г., 13:42
-- Версия сервера: 5.5.25
-- Версия PHP: 5.3.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `exdm`
--

-- --------------------------------------------------------

--
-- Структура таблицы `accounts`
--

CREATE TABLE IF NOT EXISTS `accounts` (
  `SID` int(11) NOT NULL AUTO_INCREMENT,
  `PName` varchar(32) COLLATE cp1251_bin NOT NULL,
  `Password` varchar(32) COLLATE cp1251_bin NOT NULL,
  `RegisterDate` varchar(16) COLLATE cp1251_bin NOT NULL,
  `RegisterIP` varchar(16) COLLATE cp1251_bin NOT NULL,
  `Model` int(6) NOT NULL,
  `Admin` int(4) NOT NULL DEFAULT '0',
  `Level` int(11) NOT NULL DEFAULT '0',
  `Exp` int(11) NOT NULL DEFAULT '0',
  `Spawn` int(6) NOT NULL DEFAULT '0',
  `SpawnStyle` int(11) NOT NULL DEFAULT '0',
  `Invisible` int(4) NOT NULL DEFAULT '0',
  `Time` int(16) NOT NULL DEFAULT '0',
  `Cash` int(11) NOT NULL DEFAULT '500',
  `Bank` int(20) NOT NULL DEFAULT '0',
  `Banned` int(3) NOT NULL DEFAULT '0',
  `BannedBy` varchar(25) COLLATE cp1251_bin NOT NULL DEFAULT 'Null',
  `BanReason` varchar(41) COLLATE cp1251_bin NOT NULL DEFAULT 'Null',
  `Muted` int(11) NOT NULL DEFAULT '0',
  `MutedBy` varchar(25) COLLATE cp1251_bin NOT NULL DEFAULT 'Null',
  `Slot1` int(4) NOT NULL DEFAULT '0',
  `Slot2` int(4) NOT NULL DEFAULT '0',
  `Slot3` int(4) NOT NULL DEFAULT '0',
  `Slot4` int(4) NOT NULL DEFAULT '0',
  `Slot5` int(4) NOT NULL DEFAULT '0',
  `Slot6` int(4) NOT NULL DEFAULT '0',
  `Slot7` int(4) NOT NULL DEFAULT '0',
  `Slot8` int(4) NOT NULL DEFAULT '0',
  `Slot9` int(4) NOT NULL DEFAULT '0',
  `Slot10` int(4) NOT NULL DEFAULT '0',
  `MyClan` int(6) NOT NULL DEFAULT '0',
  `Member` int(11) NOT NULL DEFAULT '0',
  `Leader` int(6) NOT NULL DEFAULT '0',
  `Home` int(11) NOT NULL DEFAULT '0',
  `Account` int(11) NOT NULL DEFAULT '0',
  `CarSlot1` int(6) NOT NULL DEFAULT '462',
  `CarSlot1Color1` int(11) NOT NULL DEFAULT '1',
  `CarSlot1Color2` int(11) NOT NULL DEFAULT '1',
  `CarSlot2` int(6) NOT NULL DEFAULT '496',
  `CarSlot2Color1` int(11) NOT NULL DEFAULT '1',
  `CarSlot2Color2` int(11) NOT NULL DEFAULT '1',
  `CarSlot3` int(6) NOT NULL DEFAULT '0',
  `CarSlot3Color1` int(11) NOT NULL DEFAULT '1',
  `CarSlot3Color2` int(11) NOT NULL DEFAULT '1',
  `GameGold` float NOT NULL DEFAULT '0',
  `GameGoldTotal` float NOT NULL DEFAULT '0',
  `GPremium` int(6) NOT NULL DEFAULT '0',
  `SkillHP` int(11) NOT NULL DEFAULT '0',
  `SkillRepair` int(11) NOT NULL DEFAULT '0',
  `ActiveSkillPerson` int(11) NOT NULL DEFAULT '0',
  `ActiveSkillCar1` int(11) NOT NULL DEFAULT '0',
  `ActiveSkillCar2` int(11) NOT NULL DEFAULT '0',
  `ActiveSkillHCar1` int(11) NOT NULL DEFAULT '0',
  `ActiveSkillHCar2` int(11) NOT NULL DEFAULT '0',
  `Prestige` int(4) NOT NULL DEFAULT '0',
  `Karma` int(11) NOT NULL DEFAULT '250',
  `KarmaTime` int(11) NOT NULL DEFAULT '0',
  `PosX` float NOT NULL DEFAULT '0',
  `PosY` float NOT NULL DEFAULT '0',
  `PosZ` float NOT NULL DEFAULT '0',
  `PosA` float NOT NULL DEFAULT '0',
  `ConPM` int(3) NOT NULL DEFAULT '1',
  `ConInviteClan` int(3) NOT NULL DEFAULT '1',
  `ConInvitePVP` int(3) NOT NULL DEFAULT '1',
  `ConMesPVP` int(3) NOT NULL DEFAULT '1',
  `ConMesEnterExit` int(3) NOT NULL DEFAULT '0',
  `ConSpeedo` int(3) NOT NULL DEFAULT '1',
  `Radar` int(3) NOT NULL DEFAULT '1',
  `Mrf2` int(11) NOT NULL DEFAULT '0',
  `Types` int(11) NOT NULL DEFAULT '0',
  `LastHourExp` int(11) NOT NULL DEFAULT '0',
  `LastHourReferalExp` int(11) NOT NULL DEFAULT '0',
  `PlayerLimitXPDate` varchar(16) COLLATE cp1251_bin NOT NULL DEFAULT 'Null',
  `LastIP` varchar(16) COLLATE cp1251_bin NOT NULL,
  `HelpTime` int(11) NOT NULL DEFAULT '500',
  `EventChangeTime` int(11) NOT NULL DEFAULT '0',
  `LeaveZM` int(11) NOT NULL DEFAULT '0',
  `ClanWarTime` int(11) NOT NULL DEFAULT '0',
  `CasinoBalance` int(16) NOT NULL DEFAULT '0',
  `GiveCashBalance` int(16) NOT NULL DEFAULT '0',
  `ChatName` varchar(80) COLLATE cp1251_bin NOT NULL,
  `BuddhaTime` int(11) NOT NULL DEFAULT '0',
  `PrestigeColor` int(11) NOT NULL DEFAULT '-1',
  `Quest1` int(6) NOT NULL DEFAULT '25',
  `Quest1Score` int(11) NOT NULL DEFAULT '0',
  `Quest1Time` int(11) NOT NULL DEFAULT '0',
  `Quest2` int(6) NOT NULL DEFAULT '28',
  `Quest2Score` int(11) NOT NULL DEFAULT '0',
  `Quest2Time` int(11) NOT NULL DEFAULT '0',
  `Quest3` int(6) NOT NULL DEFAULT '29',
  `Quest3Score` int(11) NOT NULL DEFAULT '0',
  `Quest3Time` int(11) NOT NULL DEFAULT '0',
  `Medals` int(11) NOT NULL DEFAULT '0',
  `CompletedQuests` int(11) NOT NULL DEFAULT '0',
  `GGFromMedals` float NOT NULL DEFAULT '0',
  `GGFromMedalsTotal` float NOT NULL DEFAULT '0',
  `GGFromMedalsLastDay` float NOT NULL DEFAULT '0',
  `FindPack` int(11) NOT NULL DEFAULT '0',
  `ReadObnov` int(4) NOT NULL DEFAULT '0',
  `Bonus` int(4) NOT NULL DEFAULT '0',
  `SlivBlock` int(11) NOT NULL DEFAULT '-1',
  `Tag` int(4) NOT NULL DEFAULT '0',
  `CS1PJ` int(11) NOT NULL DEFAULT '-1',
  `CS1Neon` int(6) NOT NULL DEFAULT '0',
  `CS1Fire` int(4) NOT NULL DEFAULT '0',
  `CS1Sir` int(4) NOT NULL DEFAULT '0',
  `CS1Mig` int(8) NOT NULL DEFAULT '0',
  `CS1C0` int(6) NOT NULL DEFAULT '0',
  `CS1C1` int(6) NOT NULL DEFAULT '0',
  `CS1C2` int(6) NOT NULL DEFAULT '0',
  `CS1C3` int(6) NOT NULL DEFAULT '0',
  `CS1C4` int(6) NOT NULL DEFAULT '0',
  `CS1C5` int(6) NOT NULL DEFAULT '0',
  `CS1C6` int(6) NOT NULL DEFAULT '0',
  `CS1C7` int(6) NOT NULL DEFAULT '0',
  `CS1C8` int(6) NOT NULL DEFAULT '0',
  `CS1C9` int(6) NOT NULL DEFAULT '0',
  `CS1C10` int(6) NOT NULL DEFAULT '0',
  `CS1C11` int(6) NOT NULL DEFAULT '0',
  `CS1C12` int(6) NOT NULL DEFAULT '0',
  `CS1C13` int(6) NOT NULL DEFAULT '0',
  `CS1NitroX` int(6) NOT NULL DEFAULT '0',
  `CS2PJ` int(6) NOT NULL DEFAULT '-1',
  `CS2Neon` int(8) NOT NULL DEFAULT '0',
  `CS2Fire` int(6) NOT NULL DEFAULT '0',
  `CS2Sir` int(4) NOT NULL DEFAULT '0',
  `CS2Mig` int(8) NOT NULL DEFAULT '0',
  `CS2C0` int(6) NOT NULL DEFAULT '0',
  `CS2C1` int(6) NOT NULL DEFAULT '0',
  `CS2C2` int(6) NOT NULL DEFAULT '0',
  `CS2C3` int(6) NOT NULL DEFAULT '0',
  `CS2C4` int(6) NOT NULL DEFAULT '0',
  `CS2C5` int(6) NOT NULL DEFAULT '0',
  `CS2C6` int(6) NOT NULL DEFAULT '0',
  `CS2C7` int(6) NOT NULL DEFAULT '0',
  `CS2C8` int(6) NOT NULL DEFAULT '0',
  `CS2C9` int(6) NOT NULL DEFAULT '0',
  `CS2C10` int(6) NOT NULL DEFAULT '0',
  `CS2C11` int(6) NOT NULL DEFAULT '0',
  `CS2C12` int(6) NOT NULL DEFAULT '0',
  `CS2C13` int(6) NOT NULL DEFAULT '0',
  `CS2NitroX` int(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`SID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Структура таблицы `bases`
--

CREATE TABLE IF NOT EXISTS `bases` (
  `BID` int(11) NOT NULL AUTO_INCREMENT,
  `Clan` int(11) NOT NULL,
  `Price` int(11) NOT NULL,
  `PosEnterX` float NOT NULL,
  `PosEnterY` float NOT NULL,
  `PosEnterZ` float NOT NULL,
  `PosEnterA` float NOT NULL,
  `PosRespawnX` float NOT NULL,
  `PosRespawnY` float NOT NULL,
  `PosRespawnZ` float NOT NULL,
  `PosRespawnA` float NOT NULL,
  PRIMARY KEY (`BID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Структура таблицы `clans`
--

CREATE TABLE IF NOT EXISTS `clans` (
  `CID` int(11) NOT NULL,
  `Name` varchar(64) COLLATE cp1251_bin NOT NULL,
  `Lider` varchar(32) COLLATE cp1251_bin NOT NULL,
  `Level` int(6) NOT NULL,
  `Message` varchar(125) COLLATE cp1251_bin NOT NULL,
  `Color` int(6) NOT NULL,
  `Base` int(6) NOT NULL,
  `XP` int(16) NOT NULL,
  `LastDay` int(11) NOT NULL,
  `EnemyClan` int(6) NOT NULL,
  `CWwin` int(11) NOT NULL,
  `ClanBank` int(11) NOT NULL,
  `ClanZones` int(11) NOT NULL,
  `CTag` varchar(11) COLLATE cp1251_bin NOT NULL,
  `Mem1` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem2` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem3` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem4` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem5` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem6` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem7` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem8` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem9` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem10` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem11` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem12` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem13` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem14` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem15` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem16` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem17` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem18` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem19` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Mem20` varchar(25) COLLATE cp1251_bin NOT NULL,
  PRIMARY KEY (`CID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

-- --------------------------------------------------------

--
-- Структура таблицы `houses`
--

CREATE TABLE IF NOT EXISTS `houses` (
  `HID` int(11) NOT NULL AUTO_INCREMENT,
  `Owner` varchar(64) COLLATE cp1251_bin NOT NULL,
  `Name` varchar(64) COLLATE cp1251_bin NOT NULL,
  `Price` int(11) NOT NULL,
  `PosEnterX` float NOT NULL,
  `PosEnterY` float NOT NULL,
  `PosEnterZ` float NOT NULL,
  `PosEnterA` float NOT NULL,
  `PosRespawnX` float NOT NULL,
  `PosRespawnY` float NOT NULL,
  `PosRespawnZ` float NOT NULL,
  `PosRespawnA` float NOT NULL,
  `Opened` int(11) NOT NULL,
  `BuyBlock` int(11) NOT NULL,
  PRIMARY KEY (`HID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Структура таблицы `pupdate`
--

CREATE TABLE IF NOT EXISTS `pupdate` (
  `SID` int(11) NOT NULL,
  `ALevel` int(11) NOT NULL,
  `AExp` int(11) NOT NULL,
  `ABank` int(11) NOT NULL,
  `ADonate` float NOT NULL,
  `AVip` int(11) NOT NULL,
  `APrestige` int(11) NOT NULL,
  PRIMARY KEY (`SID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

-- --------------------------------------------------------

--
-- Структура таблицы `zones`
--

CREATE TABLE IF NOT EXISTS `zones` (
  `ZID` int(11) NOT NULL AUTO_INCREMENT,
  `ZName` varchar(25) COLLATE cp1251_bin NOT NULL,
  `ZOwner` int(11) NOT NULL,
  `ZColor` int(11) NOT NULL,
  `ZLevel` int(11) NOT NULL,
  `ZCost` int(11) NOT NULL,
  `ZCTime` int(11) NOT NULL,
  `ZExp` int(11) NOT NULL,
  `ZCash` int(11) NOT NULL,
  `MinX` float NOT NULL,
  `MaxX` float NOT NULL,
  `MinY` float NOT NULL,
  `MaxY` float NOT NULL,
  PRIMARY KEY (`ZID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
