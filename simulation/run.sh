for model in gnp ba ws; do
	mkdir -p ../output/$model/$vac/no_control
	
	for vac in degree_vaccination random_vaccination; do
		for ir_val in 30 45 60 75; do
			mkdir -p ../output/$model/$vac/immunization_rate/i$ir_val
		done
		for vr_val in 01 02 03 005; do
			mkdir -p ../output/$model/$vac/vaccination_rate/v$vr_val
		done
	done
	
	for ad_val in 30 45 60 75; do
		mkdir -p ../output/$model/quarantine/adherence/a$ad_val
	done
	for time_val in w001_t60 w01_t15 w005_t30 w05_t7; do
		mkdir -p ../output/$model/quarantine/time/$time_val
	done
done

SECONDS=0
echo 'Running No Control...'
../scripts/run_no_control.sh
echo 'Finished No Control!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Quarantine (time)...'
../scripts/run_quarantine_time.sh
echo 'Finished Quarantine (time)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Quarantine (adherence)...'
../scripts/run_quarantine_adherence.sh
echo 'Finished Quarantine (adherence)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Random Vaccination (vaccination rate)...'
../scripts/run_random_vaccination_vrate.sh
echo 'Finished Random Vaccination (vaccination rate)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Random Vaccination (immunization rate)...'
../scripts/run_random_vaccination_irate.sh
echo 'Finished Random Vaccination (immunization rate)...!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Degree Vaccination (vaccination rate)...'
../scripts/run_degree_vaccination_vrate.sh
echo 'Finished Degree Vaccination (vaccination rate)!' '('$SECONDS' segundos)'

SECONDS=0
echo 'Running Degree Vaccination (immunization rate)...'
../scripts/run_degree_vaccination_irate.sh
echo 'Finished Degree Vaccination (immunization rate)!' '('$SECONDS' segundos)'