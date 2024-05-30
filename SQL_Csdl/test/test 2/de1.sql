
use csdl_bongda;
-- 1 Lập danh sách các cầu thủ Barcelona
SELECT * 
FROM
    PLAYER
WHERE
    TeamName = "Barcelona";

-- 2. Các trận thi đấu được tổ chứ ở tp Barcelona

SELECT GameID
FROM
    GAME JOIN STADIUM ON GAME.StadName = STADIUM.StadName
WHERE
    STADIUM.City = "Barcelona";

-- 3. Cho biết họ tên, vị trí thi đấu, chiều cao, cân nặng, mức lương cầu thủ thuộc đội bóng ở 
--  tp Anfield, sắp giảm theo lương và tăng chiều cao

SELECT Fname, MName, Lname, Position, Height, Weight, Salary
FROM
    PLAYER JOIN CONTRACT ON PLAYER.ContractID = CONTRACT.ContractID
ORDER BY
    Salary DESC , Height ASC;


-- 4. Lập danh sách các vị trí đâu, tổng số cầu thủ ở vị trí đó và mức lương trung bình của họ

WITH luong_trung_binh (Position, LuongTB)
AS
(SELECT PLAYER.Position, AVG(Salary)
FROM PLAYER JOIN CONTRACT ON PLAYER.ContractID = CONTRACT.ContractID
GROUP BY
    PLAYER.Position
)

SELECT PLAYER.Position, COUNT(*), LuongTB
FROM
    PLAYER JOIN luong_trung_binh ON PLAYER.Position = luong_trung_binh.Position
GROUP BY
    PLAYER.Position;

-- 5. Lập danh sách quốc tịch có ít nhất 2 cầu thủ với mức lương trên 70.000.000 có quốc tịch đó

SELECT Nationality, COUNT(*) AS "So cau thu"
FROM
    PLAYER JOIN CONTRACT ON PLAYER.ContractID = CONTRACT.ContractID
WHERE
    Salary > 70000000
GROUP BY
    Nationality
HAVING
    COUNT(*) >= 2;

-- 6. Với mỗi trọng tài, cho biết mã số, họ tên, tổng số trận thi đấu mà họ điều hành

SELECT REFEREE.RefereeID, Fname, MName, Lname, COUNT(*) as "So tran"
FROM
    REFEREE JOIN OFFICIATES ON REFEREE.RefereeID = OFFICIATES.RefereeID
GROUP BY
    REFEREE.RefereeID, Fname, MName, Lname;

-- 7. Với mỗi huấn luyện viên trưởng (vai trò là Head), cho biết họ tên, tên đội bóng, tổng số cầu thủ có
-- quốc tịch Spanish mà họ hướng dẫn


SELECT t.TeamName, COALESCE(COUNT(p.PlayerID), 0) AS "So cau thu"
FROM TEAM t
LEFT JOIN PLAYER p ON t.TeamName = p.TeamName AND p.Nationality = 'Spanish'
GROUP BY t.TeamName;


-- 8. Lập danh sách các cầu thủ ghi nhiều bàn thắng nhất. Danh sách có họ tên, quốc tịch,
-- tên đội bóng. sắp xếp theo quốc tịch


SELECT Fname, Nationality, TeamName, Goals
FROM
    PLAYER JOIN STATS ON PLAYER.PlayerID = STATS.PlayerID
ORDER BY
    Goals DESC, Nationality;

-- 9. Cho biết họ tên các cầu thủ tham gia tất cả các trận đấu của đội bóng Numancia
-- trong tháng 4/2016

SELECT 
    COUNT(*)
FROM 
    GAME
WHERE
    MONTH(MDate) = 4 AND YEAR(MDate) = 2016 AND (HomeTeam = 'Numancia' OR AwayTeam = 'Numancia');


SELECT PLAYER.PlayerID, Fname, MName, Lname
FROM
    PLAYER JOIN PLAYSIN ON PLAYER.PlayerID = PLAYSIN.PlayerID
WHERE
    PLAYSIN.GameID IN (
        SELECT 
            GameID
        FROM 
            GAME
        WHERE
            MONTH(MDate) = 4 
            AND YEAR(MDate) = 2016 
            AND (HomeTeam = 'Numancia' OR AwayTeam = 'Numancia')
    )
GROUP BY
    PlayerID
HAVING
    COUNT(*) = (
            SELECT 
                COUNT(*)
            FROM 
                GAME
            WHERE
                MONTH(MDate) = 4 
                AND YEAR(MDate) = 2016 
                AND (HomeTeam = 'Numancia' OR AwayTeam = 'Numancia')
        );


-- 10 Truy vấn tên, lương, đội tuyển, lương trung bình của đội tuyển ứng với cầu thủ đó

WITH luong_trung_binh (TeamName, LuongTB)
AS
(SELECT TEAM.TeamName, AVG(Salary)
FROM TEAM JOIN PLAYER ON TEAM.TeamName = PLAYER.TeamName JOIN contract ON PLAYER.ContractID = contract.ContractID
GROUP BY
    TEAM.TeamName
)

SELECT Fname, MName, Lname, c.Salary, t.TeamName, luong_trung_binh.LuongTB
FROM
    PLAYER p LEFT JOIN contract c ON p.ContractID = c.ContractID JOIN TEAM t ON p.TeamName = t.TeamName
    JOIN luong_trung_binh ON t.TeamName = luong_trung_binh.TeamName;



