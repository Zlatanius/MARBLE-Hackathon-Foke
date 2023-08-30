from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='marble_pkg',
            namespace='marble_pkg',
            executable='inference',
            name='inference'
        ),
        TimerAction(
            period=15.0,
            actions=[
                Node(
                    package='marble_pkg',
                    namespace='marble_pkg',
                    executable='tracking',
                    name='tracking'
                ),
                Node(
                    package='marble_pkg',
                    namespace='marble_pkg',
                    executable='gnss_conversion',
                    name='gnss_conversion'
                )
            ]),
        TimerAction(
            period=30.0,
            actions=[
                Node(
                    package='comm_pkg',
                    namespace='comm_pkg',
                    executable='univerzalni_node',
                    name='univerzalni_node'
                ),
            ])
    ])
