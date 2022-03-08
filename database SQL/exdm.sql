-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Апр 07 2016 г., 08:25
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
  `SID` int(11) NOT NULL,
  `PName` varchar(64) COLLATE cp1251_bin NOT NULL,
  `Password` varchar(64) COLLATE cp1251_bin NOT NULL,
  `RegisterDate` varchar(16) COLLATE cp1251_bin NOT NULL,
  `RegisterIP` varchar(16) COLLATE cp1251_bin NOT NULL,
  `Model` int(6) NOT NULL,
  `Admin` int(4) NOT NULL,
  `Level` int(11) NOT NULL,
  `Exp` int(11) NOT NULL,
  `Spawn` int(6) NOT NULL,
  `SpawnStyle` int(11) NOT NULL,
  `Invisible` int(4) NOT NULL,
  `Time` int(16) NOT NULL,
  `Cash` int(11) NOT NULL,
  `Bank` int(20) NOT NULL,
  `Banned` int(3) NOT NULL,
  `BannedBy` varchar(25) COLLATE cp1251_bin NOT NULL,
  `BanReason` varchar(41) COLLATE cp1251_bin NOT NULL,
  `Muted` int(11) NOT NULL,
  `MutedBy` varchar(25) COLLATE cp1251_bin NOT NULL,
  `Slot1` int(4) NOT NULL,
  `Slot2` int(4) NOT NULL,
  `Slot3` int(4) NOT NULL,
  `Slot4` int(4) NOT NULL,
  `Slot5` int(4) NOT NULL,
  `Slot6` int(4) NOT NULL,
  `Slot7` int(4) NOT NULL,
  `Slot8` int(4) NOT NULL,
  `Slot9` int(4) NOT NULL,
  `Slot10` int(4) NOT NULL,
  `MyClan` int(6) NOT NULL,
  `Member` int(11) NOT NULL,
  `Leader` int(6) NOT NULL,
  `Home` int(11) NOT NULL,
  `Account` int(11) NOT NULL,
  `CarSlot1` int(6) NOT NULL,
  `CarSlot1Color1` int(11) NOT NULL,
  `CarSlot1Color2` int(11) NOT NULL,
  `CarSlot2` int(6) NOT NULL,
  `CarSlot2Color1` int(11) NOT NULL,
  `CarSlot2Color2` int(11) NOT NULL,
  `CarSlot3` int(6) NOT NULL,
  `CarSlot3Color1` int(11) NOT NULL,
  `CarSlot3Color2` int(11) NOT NULL,
  `GameGold` float NOT NULL,
  `GameGoldTotal` float NOT NULL,
  `GPremium` int(6) NOT NULL,
  `SkillHP` int(11) NOT NULL,
  `SkillRepair` int(11) NOT NULL,
  `ActiveSkillPerson` int(11) NOT NULL,
  `ActiveSkillCar1` int(11) NOT NULL,
  `ActiveSkillCar2` int(11) NOT NULL,
  `ActiveSkillHCar1` int(11) NOT NULL,
  `ActiveSkillHCar2` int(11) NOT NULL,
  `Prestige` int(4) NOT NULL,
  `Karma` int(11) NOT NULL,
  `KarmaTime` int(11) NOT NULL,
  `PosX` float NOT NULL,
  `PosY` float NOT NULL,
  `PosZ` float NOT NULL,
  `PosA` float NOT NULL,
  `ConPM` int(3) NOT NULL,
  `ConInviteClan` int(3) NOT NULL,
  `ConInvitePVP` int(3) NOT NULL,
  `ConMesPVP` int(3) NOT NULL,
  `ConMesEnterExit` int(3) NOT NULL,
  `ConSpeedo` int(3) NOT NULL,
  `Radar` int(3) NOT NULL,
  `Mrf2` int(11) NOT NULL,
  `Types` int(11) NOT NULL,
  `LastHourExp` int(11) NOT NULL,
  `LastHourReferalExp` int(11) NOT NULL,
  `PlayerLimitXPDate` varchar(16) COLLATE cp1251_bin NOT NULL,
  `LastIP` varchar(16) COLLATE cp1251_bin NOT NULL,
  `HelpTime` int(11) NOT NULL,
  `EventChangeTime` int(11) NOT NULL,
  `LeaveZM` int(11) NOT NULL,
  `ClanWarTime` int(11) NOT NULL,
  `CasinoBalance` int(16) NOT NULL,
  `GiveCashBalance` int(16) NOT NULL,
  `ChatName` varchar(80) COLLATE cp1251_bin NOT NULL,
  `BuddhaTime` int(11) NOT NULL,
  `PrestigeColor` int(11) NOT NULL,
  `Quest1` int(6) NOT NULL,
  `Quest1Score` int(11) NOT NULL,
  `Quest1Time` int(11) NOT NULL,
  `Quest2` int(6) NOT NULL,
  `Quest2Score` int(11) NOT NULL,
  `Quest2Time` int(11) NOT NULL,
  `Quest3` int(6) NOT NULL,
  `Quest3Score` int(11) NOT NULL,
  `Quest3Time` int(11) NOT NULL,
  `Medals` int(11) NOT NULL,
  `CompletedQuests` int(11) NOT NULL,
  `GGFromMedals` float NOT NULL,
  `GGFromMedalsTotal` float NOT NULL,
  `GGFromMedalsLastDay` float NOT NULL,
  `FindPack` int(11) NOT NULL,
  `ReadObnov` int(4) NOT NULL,
  `Bonus` int(4) NOT NULL,
  `SlivBlock` int(11) NOT NULL,
  `Tag` int(4) NOT NULL,
  `CarSlot1PaintJob` int(11) NOT NULL,
  `CarSlot1Neon` int(6) NOT NULL,
  `CarSlot1Fire` int(4) NOT NULL,
  `CS1Sir` int(4) NOT NULL,
  `CS1Mig` int(4) NOT NULL,
  `CarSlot1Component0` int(6) NOT NULL,
  `CarSlot1Component1` int(6) NOT NULL,
  `CarSlot1Component2` int(6) NOT NULL,
  `CarSlot1Component3` int(6) NOT NULL,
  `CarSlot1Component4` int(6) NOT NULL,
  `CarSlot1Component5` int(6) NOT NULL,
  `CarSlot1Component6` int(6) NOT NULL,
  `CarSlot1Component7` int(6) NOT NULL,
  `CarSlot1Component8` int(6) NOT NULL,
  `CarSlot1Component9` int(6) NOT NULL,
  `CarSlot1Component10` int(6) NOT NULL,
  `CarSlot1Component11` int(6) NOT NULL,
  `CarSlot1Component12` int(6) NOT NULL,
  `CarSlot1Component13` int(6) NOT NULL,
  `CarSlot1NitroX` int(6) NOT NULL,
  `CarSlot2PaintJob` int(6) NOT NULL,
  `CarSlot2Neon` int(6) NOT NULL,
  `CarSlot2Fire` int(6) NOT NULL,
  `CS2Sir` int(4) NOT NULL,
  `CS2Mig` int(4) NOT NULL,
  `CarSlot2Component0` int(6) NOT NULL,
  `CarSlot2Component1` int(6) NOT NULL,
  `CarSlot2Component2` int(6) NOT NULL,
  `CarSlot2Component3` int(6) NOT NULL,
  `CarSlot2Component4` int(6) NOT NULL,
  `CarSlot2Component5` int(6) NOT NULL,
  `CarSlot2Component6` int(6) NOT NULL,
  `CarSlot2Component7` int(6) NOT NULL,
  `CarSlot2Component8` int(6) NOT NULL,
  `CarSlot2Component9` int(6) NOT NULL,
  `CarSlot2Component10` int(6) NOT NULL,
  `CarSlot2Component11` int(6) NOT NULL,
  `CarSlot2Component12` int(6) NOT NULL,
  `CarSlot2Component13` int(6) NOT NULL,
  `CarSlot2NitroX` int(6) NOT NULL,
  PRIMARY KEY (`SID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

-- --------------------------------------------------------

--
-- Структура таблицы `bases`
--

CREATE TABLE IF NOT EXISTS `bases` (
  `BID` int(11) NOT NULL,
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
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

--
-- Дамп данных таблицы `bases`
--

INSERT INTO `bases` (`BID`, `Clan`, `Price`, `PosEnterX`, `PosEnterY`, `PosEnterZ`, `PosEnterA`, `PosRespawnX`, `PosRespawnY`, `PosRespawnZ`, `PosRespawnA`) VALUES
(0, 0, 123, 0, 0, 0, 0, 0, 0, 0, 0);

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

--
-- Дамп данных таблицы `clans`
--

INSERT INTO `clans` (`CID`, `Name`, `Lider`, `Level`, `Message`, `Color`, `Base`, `XP`, `LastDay`, `EnemyClan`, `CWwin`, `ClanBank`, `ClanZones`, `CTag`, `Mem1`, `Mem2`, `Mem3`, `Mem4`, `Mem5`, `Mem6`, `Mem7`, `Mem8`, `Mem9`, `Mem10`, `Mem11`, `Mem12`, `Mem13`, `Mem14`, `Mem15`, `Mem16`, `Mem17`, `Mem18`, `Mem19`, `Mem20`) VALUES
(0, 'reserv', 'reserv', 4, 'reserv', 0, 0, 0, 0, 0, 0, 0, 0, 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null', 'null');

-- --------------------------------------------------------

--
-- Структура таблицы `houses`
--

CREATE TABLE IF NOT EXISTS `houses` (
  `HID` int(11) NOT NULL,
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
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

--
-- Дамп данных таблицы `houses`
--

INSERT INTO `houses` (`HID`, `Owner`, `Name`, `Price`, `PosEnterX`, `PosEnterY`, `PosEnterZ`, `PosEnterA`, `PosRespawnX`, `PosRespawnY`, `PosRespawnZ`, `PosRespawnA`, `Opened`, `BuyBlock`) VALUES
(0, 'null', 'null', 123, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Структура таблицы `pupdate`
--

CREATE TABLE IF NOT EXISTS `pupdate` (
  `PID` int(11) NOT NULL,
  `ALevel` int(11) NOT NULL,
  `AExp` int(11) NOT NULL,
  `ABank` int(11) NOT NULL,
  `ADonate` float NOT NULL,
  `AVip` int(11) NOT NULL,
  `APrestige` int(11) NOT NULL,
  PRIMARY KEY (`PID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

-- --------------------------------------------------------

--
-- Структура таблицы `zones`
--

CREATE TABLE IF NOT EXISTS `zones` (
  `ZID` int(11) NOT NULL,
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
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

--
-- Дамп данных таблицы `zones`
--

INSERT INTO `zones` (`ZID`, `ZName`, `ZOwner`, `ZColor`, `ZLevel`, `ZCost`, `ZCTime`, `ZExp`, `ZCash`, `MinX`, `MaxX`, `MinY`, `MaxY`) VALUES
(0, 'null', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
