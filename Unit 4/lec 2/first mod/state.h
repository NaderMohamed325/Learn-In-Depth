/*
 * state.h
 *
 *  Created on: Jun 18, 2024
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_
#endif /* STATE_H_ */
