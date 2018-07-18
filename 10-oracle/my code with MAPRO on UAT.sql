/*------------------table-----------------------------------------------------*/
desc EGISEDT.T_GATE_CHECK;
select count(*) from EGISEDT.t_gate_check where check_query like '%T_TRK_RULE%'; --/* 14 result */
select count(*) from EGISEDT.t_gate_check where check_query like '%T_TRK_SPD%';  --/* 14 result */
select count(*) from EGISEDT.t_gate_check where check_query like '%T_TRK_SPD_COND%'; --/* 11 result */

/*----------------------view---------------------------------------------*/
desc all_views;
select * from all_views where owner = 'EGISEDT';

select * 
from all_views
where owner = 'EGISEDT' and text_vc like '%T_TRK_RULE%';  /*text is long and text_vc is varchar2(4000)*/ /* 0 results */

select * 
from all_views
where owner = 'EGISEDT' and text_vc like '%T_TRK_SPD%'; /* 0 results */

select * 
from all_views
where owner = 'EGISEDT' and text_vc like '%T_TRK_SPD_COND%'; /* 0 result */


/*------------------------------packages------------------------------------------*/
desc all_source;

SELECT count(*) FROM all_source where text like '%T_TRK_RULE%'; -- result 0
SELECT count(*) FROM all_source where text like '%T_TRK_SPD%'; -- result 2
SELECT count(*) FROM all_source where text like '%T_TRK_SPD_COND%'; --result 0



/*-----------------------trigger----------------0-----------------------*/
desc all_triggers;
select * from all_triggers where owner = 'EGISEDT';  -- 1

/*--------------users (databases)----------------------------*/
--list all the databases
SELECT USERNAME FROM ALL_USERS ORDER BY USERNAME; 

--list all the tables in EGISEDT database
select * from all_tables where owner = 'EGISEDT'; 


