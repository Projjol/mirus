# Copyright 2013 Joshua Beitler

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

# http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

error_cp = false

# generate a bootable iso image of Mirus
desc "Creates bootable media"
task :make_iso => ['build_asm', 'build_kernel', 'link', 'build_ramdisk'] do
    sh "cp ./build/kernel.bin ./iso/boot/kernel.bin >>./build/logs/isolog.log 2>&1" do |ok, res|
        if ! ok
<<<<<<< HEAD
            puts "    --> Could not copy kernel image to ISO directory!".red
=======
            puts "-- Could not copy kernel image to ISO directory!".red
>>>>>>> upstream/master
            $errors = true
            error_cp = true
        end
    end

    if ! error_cp
        sh "grub2-mkrescue -o ./build/#{$target_iso} iso >>./build/logs/isolog.log 2>&1" do |ok, res|
            if ! ok
<<<<<<< HEAD
                puts "    --> Could not generate disk image".red
                $errors = true
            else
                puts "    --> Generating disk image"
=======
                puts "-- Could not generate disk image".red
                $errors = true
            else
                puts "-- Generating disk image"
>>>>>>> upstream/master
            end
        end
    end
end
