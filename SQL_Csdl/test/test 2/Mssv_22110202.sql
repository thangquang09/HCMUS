-- 22110202
-- Ly Quang Thang
-- MySQL


use Csdl_BongDa;

-- 1. Cho biết các họ tên, vị trí, mức lương của các cầu thủ thuộc đội bóng Real Madrid.

SELECT PLAYER.Fname, PLAYER.MName, PLAYER.Lname, PLAYER.Position, CONTRACT.Salary
FROM
    PLAYER JOIN CONTRACT ON PLAYER.ContractID = CONTRACT.ContractID
WHERE
    PLAYER.TeamName = "Real Madrid";

-- 2. Lập danh sách tên, website, thành phố của đội bóng và tên huấn luyện viên trưởng 
-- (vai trò là Head) 
-- tương ứng của các đội bóng có huấn luyện viên trưởng dưới 70 tuổi.

SELECT TEAM.TeamName, TEAM.Website, TEAM.City, COACH.Fname, COACH.MName, COACH.Lname
FROM
    TEAM JOIN COACH ON TEAM.TeamName = COACH.TeamName
WHERE
    COACH.Type = "Head" AND TIMESTAMPDIFF(YEAR, COACH.BirthDay, CURDATE()) < 70;

-- 3. Lập danh sách các cầu thủ có mức lương trên 75,000,000 
-- thuộc đội bóng của huấn luyện viên Carlo Ancelotti.
SELECT p.Fname, p.MName, p.Lname, c.Salary
FROM
    PLAYER p JOIN CONTRACT c ON p.ContractID = c.ContractID
WHERE
    p.TeamName = (SELECT TeamName FROM COACH WHERE Fname = "Carlo" AND MName = "" AND Lname = "Ancelotti")
    AND
    c.Salary > 75000000;

-- 4. Lập danh sách tên đội bóng, tên viết tắt của đội bóng, tổng số cầu thủ 
-- và chiều cao trung bình của đội bóng đó.

WITH chieu_cao_trung_binh(TeamName, ChieuCaoTB)
AS
(
    SELECT TeamName, AVG(Height)
    FROM PLAYER
    GROUP BY TeamName
)

SELECT TEAM.TeamName, TEAM.Abbr, COUNT(*), ChieuCaoTB
FROM
    TEAM JOIN chieu_cao_trung_binh ON TEAM.TeamName = chieu_cao_trung_binh.TeamName JOIN PLAYER ON TEAM.TeamName = PLAYER.TeamName
GROUP BY
    TEAM.TeamName, TEAM.Abbr, ChieuCaoTB;


-- 5. Lập danh sách tên đội bóng và mức lương trung bình của cầu thủ cho các đội bóng mức lương trung bình dưới 50,000,000.

SELECT TEAM.TeamName, AVG(Salary) AvgSalary
FROM CONTRACT JOIN PLAYER JOIN TEAM
ON PLAYER.ContractID = CONTRACT.ContractID AND TEAM.TeamName = PLAYER.TeamName
GROUP BY TEAM.TeamName
HAVING AvgSalary < 50000000;


-- 6. Với mỗi sân cầu thủ, cho biết họ tên, chiều cao, cân nặng và tổng số trận thi đấu mà cầu thủ đó đã chơi.
SELECT Fname, Mname, Lname, Height, Weight, COUNT(*) NumberOfGame
FROM PLAYER play JOIN PLAYSIN game
ON play.PlayerID = game.PlayerID
GROUP BY play.PlayerID;

-- 7.Lập danh sách tên, điểm của đội bóng có ít hơn 2 cầu thủ sinh trước năm 1990.

SELECT TeamName, Points
FROM TEAM
WHERE TeamName NOT IN (
    SELECT TeamName
    FROM PLAYER
    WHERE YEAR(BirthDay) < 1990
    GROUP BY TeamName
    HAVING COUNT(*) >= 2
);


-- 8. Lập danh sách các cầu thủ ghi ít bàn thắng nhất. Danh sách có họ tên, quốc tịch, tên đội bóng. 
-- Sắp xếp kết quả theo quốc tịch.

SELECT Fname, Mname, Lname, Nationality, TeamName, Goals
FROM
    PLAYER JOIN STATS ON PLAYER.PlayerID = STATS.PlayerID
ORDER BY Goals , Nationality;

-- 9. Cho biết họ tên các cầu thủ tham gia tất cả các trận thi đấu trên sân khách của đội bóng Numancia trong tháng 04/2016.

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
            AND (AwayTeam = 'Numancia')
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
                AND (AwayTeam = 'Numancia')
        );

-- 10. Lập danh sách gồm tên viết tắt của đội bóng, họ tên, chiều cao của các cầu thủ của đội bóng và độ lệch chiều 
-- cao của cầu thủ với chiều cao trung bình của đội bóng.

WITH chieu_cao_trung_binh(TeamName, TenVietTat, ChieuCaoTB)
AS
(
    SELECT PLAYER.TeamName, TEAM.Abbr, AVG(PLAYER.Height)
    FROM PLAYER JOIN TEAM ON PLAYER.TeamName = TEAM.TeamName
    GROUP BY TEAM.Abbr, TEAM.TeamName
)

SELECT chieu_cao_trung_binh.TenVietTat, PLAYER.Fname, PLAYER.MName, PLAYER.Lname, PLAYER.Height, ABS(Height - ChieuCaoTB) as "Do lech"
FROM
    PLAYER JOIN chieu_cao_trung_binh ON PLAYER.TeamName = chieu_cao_trung_binh.TeamName;