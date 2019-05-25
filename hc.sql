
create schema hc;

create sequence hc.game_sequo start 1;

create table hc.game (
id int primary key,
start_date bigint not null,
end_date bigint not null,
ticks int not null,
current int not null,
period int not null,
width int not null,
height int not null
);

create table hc.region (
id int primary key,
player int not null,
cell int not null,
population int not null,
defense int not null
);

create table hc.cell (
id int primary key,
longitude int not null,
lattitude int not null,
growth int not null,
defense int not null
);

create table hc.neighbor (
cell int not null,
neighbor int not null,
direction int not null
);

create table hc.player (
id int primary key,
email varchar(100) not null,
ssuid varchar(100) not null,
regions int not null,
population int not null,
rank int not null
);

create table hc.move (
player int not null,
tick int not null,
fc int not null,
tc int not null,
population int not null
);

