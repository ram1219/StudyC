#pragma once

#ifndef _POINT_H_			// _POINT_H_ 가 선언되지 않았을 경우 아래 소스 실행
#define _POINT_H_

typedef struct {
	int x;
	int y;
}Point;

#endif


/* 헤더가 중복으로 컴파일 되는 것을 막기 위해 ifndef / indef (조건부 컴파일) 를 사용한다. */
